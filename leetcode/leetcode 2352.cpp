class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map <vector <int> , int> vis;
        int n = grid.size();
        int m = grid[0].size();
        for (auto i : grid) vis[i]++;
        int cnt = 0;
        for (int j = 0; j < m;j++){
            vector <int> temp;
            temp.reserve(n);
            for (int i = 0;i < n;i++) temp.push_back(grid[i][j]);
            if (vis.count(temp)) cnt += vis[temp];
        }
        return cnt;
    }
};