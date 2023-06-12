class TreeAncestor {
private:
    struct Edge{
        int u;
        int v;
        Edge(int u , int v): u(u) , v(v){}
    };
    static const int N = 5e5 + 2, LOGN = 17;
    vector <Edge> E;
    vector <int> G[N];
    int dep[N];
    int f[N][LOGN];
    void add_edge(int u , int v){
        E.push_back({u , v});
        G[u].push_back(E.size() - 1);
    }
    void bulid(int u , int father){
        dep[u] = dep[father] + 1;
        for (int i = 1;(1 << i) <= dep[u];i++)f[u][i] = f[f[u][i - 1]][i - 1];
        for (int i : G[u]){
            int v = E[i].v;
            f[v][0] = u;
            bulid(v , u);
        }
    }
public:
    TreeAncestor(int n, vector<int>& parent) {
        memset(f , 0 , sizeof (f));
        memset(dep , 0 , sizeof (dep));
        for (int i = 0;i < n;i++) add_edge(parent[i] + 1 , i + 1); 
        bulid(1 , 0);
    }
    
    int getKthAncestor(int node, int k) {
        node++;
        int temp = dep[node] - k;
        if (dep[node] <= k) return -1;
        for (int i = LOGN - 1;i >= 0;i--){
            if (dep[f[node][i]] >= temp) node = f[node][i];
        }
        return node - 1;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */