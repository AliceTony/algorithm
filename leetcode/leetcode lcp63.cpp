class Solution {
private:
    int n , m;
    bool dfs(int x , int y , int target , int num , vector <string> &plate) {
        if (num == -1 || x == n || y == m || x == -1 || y == -1) return 0;
        if (plate[x][y] == 'O') return 1;
        else if (plate[x][y] == 'W') target = (target + 3) % 4;
        else if (plate[x][y] == 'E') target = (target + 1) % 4;
        if (target == 0 && dfs(x , y + 1 , target , num - 1 , plate)) return 1;
        if (target == 1 && dfs(x + 1 , y, target , num - 1 , plate)) return 1;
        if (target == 2 && dfs(x , y - 1, target , num - 1 , plate)) return 1;
        if (target == 3 && dfs(x - 1 , y, target , num - 1 , plate)) return 1;
        return 0;
    }
public:
    vector<vector<int>> ballGame(int num, vector<string>& plate) {
        n = plate.size() , m = plate[0].size();
        vector <vector<int>> ans;
        for (int i = 1;i < n - 1;i++){
            if (plate[i][0] == '.' && dfs(i , 0 , 0 , num , plate)) ans.push_back({i , 0});
            if (plate[i][m - 1] == '.' && dfs(i , m - 1 , 2 , num , plate)) ans.push_back({i , m - 1});
        }
        for (int i = 1;i < m - 1;i++){
            if (plate[0][i] == '.' && dfs(0 , i , 1 , num , plate)) ans.push_back({0 , i});
            if (plate[n - 1][i] == '.' && dfs(n - 1 , i , 3 , num , plate)) ans.push_back({n - 1 , i});
        }
        return ans;
    }
};