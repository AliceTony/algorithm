class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        vector <int> f(x + 10 * b + 1 , INT_MAX) ;
        vector <bool> jump(x + 10 * b + 1 , 0);
        unordered_set <int> vis;
        for (int i : forbidden) vis.insert(i);
        queue <int> q;
        q.push(0);
        f[0] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if (u == x) return f[u];
            if (!jump[u] && u - b > 0 && f[u - b] == INT_MAX && !vis.count(u - b)) {
                jump[u - b] = 1;
                f[u - b] = f[u] + 1;
                q.push(u - b);
            }
            if (u + a < f.size() && f[u + a] == INT_MAX && !vis.count(u + a)){

                f[u + a] = f[u] + 1;
                q.push(u + a);
            }
        }
        return -1;
    }
};