class Solution {
public:
    double dfs(vector <vector <int>>& E, vector <bool> vis, int i, int t, int target) {
        int next = i == 1 ? E[i].size() : E[i].size() - 1;
        if (t == 0 || next == 0) return i == target ? 1.0 : 0.0;
        vis[i] = 1;
        double res = 0;
        for (int j : E[i]) {
            if (!vis[j]) {
                res += dfs(E, vis, j, t - 1, target);
            }
        }
        return res / next;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector <vector <int>> E(n + 1);
        for (int i = 0; i < edges.size(); i++) {
            E[edges[i][0]].push_back(edges[i][1]);
            E[edges[i][1]].push_back(edges[i][0]);
        }
        vector <bool> vis(n + 1);
        return dfs(E, vis, 1, t, target);
    }
};