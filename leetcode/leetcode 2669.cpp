class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1, m = matrix.front().size(), x = 0, y = -1;
        vector <int> ans;
        while (1) {
            if (m == 0) break;
            for (int i = 0; i < m; i++) ans.push_back(matrix[x][++y]);
            m--;
            if (n == 0) break;
            for (int i = 0; i < n; i++) ans.push_back(matrix[++x][y]);
            n--;
            if (m == 0) break;
            for (int i = 0; i < m; i++) ans.push_back(matrix[x][--y]);
            m--;
            if (n == 0) break;
            for (int i = 0; i < n; i++) ans.push_back(matrix[--x][y]);
            n--;
        }
        return ans;
    }
};