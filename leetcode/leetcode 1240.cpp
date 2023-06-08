class Solution {
private:
    int ans;
    int n, m;
    void dfs(int x, int y, vector <vector <bool>>& vis, int cnt) {
        if (cnt >= ans) return;
        if (x >= n) {
            ans = cnt;
            return;
        }
        if (y >= m) {
            dfs(x + 1, 0, vis, cnt);
            return;
        }
        if (vis[x][y]) {
            dfs(x, y + 1, vis, cnt);
            return;
        }
        for (int k = min(n - x, m - y); k > 0 && check(x, y, vis, k); k--) {
            update(x, y, vis, k);
            dfs(x, y + k, vis, cnt + 1);
            update(x, y, vis, k);
        }
    }
    bool check(int x, int y, vector <vector <bool>>& vis, int k) {
        for (int i = x; i < x + k; i++) {
            for (int j = y; j < y + k; j++) {
                if (vis[i][j]) return 0;
            }
        }
        return 1;
    }
    void update(int x, int y, vector <vector <bool>>& vis, int k) {
        for (int i = x; i < x + k; i++) {
            for (int j = y; j < y + k; j++) {
                vis[i][j] = !vis[i][j];
            }
        }
    }
public:
    int tilingRectangle(int n, int m) {
        Solution::n = n;
        Solution::m = m;
        ans = max(n, m);
        vector <vector <bool>> vis(n, vector <bool>(m, 0));
        dfs(0, 0, vis, 0);
        return ans;
    }
};