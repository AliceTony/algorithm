//�ڽӱ�
class Adjacency {
private:
    struct Edge {
        int u;                                                  //��ʼ�˵�                                   
        int v;                                                  //��ֹ�˵�
        int w;                                                  //Ȩ��
        Edge(int u, int v, int w) : u(u), v(v), w(w) {}         //��Ȩ�س�ʼ��
        // Edge(int u, int v) : u(u), v(v), w(1) {}             //����Ȩ�س�ʼ�� Ĭ��Ȩ��Ϊ1
    };
    vector <Edge> E;
    vector <int> G[N];
    int dep[N];
    int f[N][LOG2_N + 1];
public:
    Adjacency() {                                                                       //��ʼ��
        memset(dep, 0, sizeof(dep));
        memset(f, 0, sizeof(dep));
    }
    void add_edge(int u, int v, int w = 1) {                                            //��ӱ�
        E.push_back({ u , v , w });
        G[u].push_back(E.size() - 1);
        E.push_back({ v , u , w });
        G[v].push_back(E.size() - 1);
    }
    void bulid(int u, int father) {
        dep[u] = dep[father] + 1;                                                       //������
        for (int i = 1; (1 << i) <= dep[u]; i++) f[u][i] = f[f[u][i - 1]][i - 1];       //����SF��
        for (int i : G[u]) {                                                            //���������ӽڵ�
            int v = E[i].v;
            if (v == father) continue;
            f[v][0] = u;
            bulid(v, u);
        }
    }
    int lca(int x, int y) {
        if (x == y) return x;
        if (dep[x] < dep[y]) swap(x, y);
        for (int i = LOG2_N; i >= 0; i--) {
            if (dep[f[x][i]] >= dep[y]) {
                x = f[x][i];
                if (x == y) return x;
            }
        }
        for (int i = LOG2_N; i >= 0; i--) {
            if (f[x][i] != f[y][i]) {
                x = f[x][i];
                y = f[y][i];
            }
        }
        return f[x][0];
    }
};