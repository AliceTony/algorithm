class Solution {
private:
    typedef pair <int, int> PII;
    const int DX[4]{ 1 , -1 , 0 , 0 }, DY[4]{ 0 , 0 , 1 , -1 };
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector <vector <int>> vis(n, vector <int>(m));
        queue<PII> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!mat[i][j]) {
                    q.push({ i , j });
                    vis[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            PII t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int dx = t.first + DX[i];
                int dy = t.second + DY[i];
                if (dx >= 0 && dy >= 0 && dx < n && dy < m && !vis[dx][dy] && mat[dx][dy]) {
                    vis[dx][dy] = vis[t.first][t.second] + 1;
                    q.push({ dx , dy });
                }
            }
        }
        return vis;
    }
};