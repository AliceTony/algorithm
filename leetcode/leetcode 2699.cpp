//未考虑到修改边权后不是最短路了

class Solution {
private:
    typedef pair<int, int> PII;
    int n;
    struct Point {
        int cost = 1e9 + 1;
        int last = -1;
    };
    unordered_map <int, vector <int>> E[100];
    vector <Point> point;
    vector <bool> vis;
    void add_edge(int u, int v, int x, bool change) {
        E[u][v].push_back(x);
        E[u][v].push_back(change);
        E[v][u].push_back(x);
        E[v][u].push_back(change);
    }
    void dijkstra(int start, vector<vector<int>>& edges) {
        priority_queue<PII, vector <PII>, greater<PII>> pq;
        pq.push({ 0 , start });
        point[start].cost = 0;
        while (!pq.empty()) {
            auto [val, u] = pq.top();
            pq.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto [v, x] : E[u]) {
                int i = x[0];
                bool change = x[1];
                if (!vis[v]) {
                    cout << u << " " << v << " " << change << " " << val + edges[i][2] << " " << point[v].cost << "\n";
                    if (change) {
                        if (val + edges[i][2] <= point[v].cost) {
                            point[v].cost = val + edges[i][2];
                            point[v].last = u;
                            pq.push({ point[v].cost , v });
                        }
                    }
                    else {
                        if (val + edges[i][2] < point[v].cost) {
                            point[v].cost = val + edges[i][2];
                            point[v].last = u;
                            pq.push({ point[v].cost , v });
                        }
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        Solution::n = n;
        point.resize(n);
        vis.resize(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i][2] == -1) {
                add_edge(edges[i][0], edges[i][1], i, 1);
                edges[i][2] = 1;
            }
            else add_edge(edges[i][0], edges[i][1], i, 0);
        }
        dijkstra(source, edges);
        int val = point[destination].cost;
        for (int i = 0; i < n; i++) {
            cout << point[i].cost << " " << point[i].last << "\n";
        }
        if (val > target)edges.clear();
        else {
            while (point[destination].last != -1) {
                if (E[destination][point[destination].last][1]) {
                    edges[E[destination][point[destination].last][0]][2] += target - val;
                    val = target;
                    break;
                }
                destination = point[destination].last;
            }
            if (val != target)edges.clear();
        }
        return edges;
    }
};

//题解
class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        this->target = target;
        vector<vector<int>> adj_matrix(n, vector<int>(n, -1));
        // 邻接矩阵中存储边的下标
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            adj_matrix[u][v] = adj_matrix[v][u] = i;
        }
        from_destination = dijkstra(0, destination, edges, adj_matrix);
        if (from_destination[source] > target) {
            return {};
        }
        vector<long long> from_source = dijkstra(1, source, edges, adj_matrix);
        if (from_source[destination] != target) {
            return {};
        }
        return edges;
    }

    vector<long long> dijkstra(int op, int source, vector<vector<int>>& edges, const vector<vector<int>>& adj_matrix) {
        // 朴素的 dijkstra 算法
        // adj_matrix 是一个邻接矩阵
        int n = adj_matrix.size();
        vector<long long> dist(n, INT_MAX / 2);
        vector<int> used(n);
        dist[source] = 0;

        for (int round = 0; round < n - 1; ++round) {
            int u = -1;
            for (int i = 0; i < n; ++i) {
                if (!used[i] && (u == -1 || dist[i] < dist[u])) {
                    u = i;
                }
            }
            used[u] = true;
            for (int v = 0; v < n; ++v) {
                if (!used[v] && adj_matrix[u][v] != -1) {
                    if (edges[adj_matrix[u][v]][2] != -1) {
                        dist[v] = min(dist[v], dist[u] + edges[adj_matrix[u][v]][2]);
                    }
                    else {
                        if (op == 0) {
                            dist[v] = min(dist[v], dist[u] + 1);
                        }
                        else {
                            int modify = target - dist[u] - from_destination[v];
                            if (modify > 0) {
                                dist[v] = min(dist[v], dist[u] + modify);
                                edges[adj_matrix[u][v]][2] = modify;
                            }
                            else {
                                edges[adj_matrix[u][v]][2] = target;
                            }
                        }
                    }

                }
            }
        }

        return dist;
    }

private:
    vector<long long> from_destination;
    int target;
};

