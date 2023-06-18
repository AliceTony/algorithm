class Solution {
private:
    const int DX[5]{1 , -1 , 0 , 0} , DY[5]{0 , 0 , 1 , -1};
    int n , m;
    typedef pair<int , int> PII;
    bool bfs(int i , int j , vector <vector<int>>& grid){
        queue<PII> q;
        q.push({i , j});
        grid[i][j] = 1;
        bool ok = 1;
        while(!q.empty()){
            auto [x , y] = q.front();
            q.pop();
            for (int i = 0;i < 4;i++){
                int dx = x + DX[i] , dy = y + DY[i];
                if (!check(dx , dy)){
                    ok = 0;
                    continue;
                }
                if (!grid[dx][dy]) q.push({dx , dy}) , grid[dx][dy] = 1;
            }
        }
        return ok;
    }
    inline bool check (int x , int y){
        return x >= 0 && y >= 0 && x < n && y < m;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size() , m = grid[0].size();
        int ans = 0;
        for(int i = 0;i < n;i++){
            for (int j = 0;j < m;j++){
                if (!grid[i][j] && bfs(i , j , grid)){
                    ans++;
                }
            }
        }
        return ans;
    }
};