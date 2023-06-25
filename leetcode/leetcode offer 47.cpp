class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        for (int i = 0;i < grid.size();i++){
            for (int j = 0;j < grid[0].size();j++){
                if (i == 0 && j == 0) continue;
                if (i == 0){
                    grid[i][j] += grid[i][j - 1];
                }
                else if (j == 0){
                    grid[i][j] += grid[i - 1][j];
                }
                else {
                    grid[i][j] += max(grid[i - 1][j] , grid[i][j - 1]);
                }
            }
        }
        return grid.back().back();
    }
};