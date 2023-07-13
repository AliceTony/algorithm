class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix.front().size();
        vector <vector <int>> f(2, vector <int>(m));
        for (int i = 0; i < m; i++) f[0][i] = matrix[0][i];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j == 0) f[1][j] = min(f[0][j], f[0][j + 1]) + matrix[i][j];
                else if (j == m - 1) f[1][j] = min(f[0][j], f[0][j - 1]) + matrix[i][j];
                else f[1][j] = min(f[0][j], min(f[0][j - 1], f[0][j + 1])) + matrix[i][j];
            }
            swap(f[0], f[1]);
        }
        int ans = 1e9;
        for (int i : f[0])ans = min(ans, i);
        return ans;
    }
};