class Solution {
private:
    const int DX[8]{-1 , 0 , 1 , -1 , 1 , -1 , 0 , 1} , DY[8]{1 , 1 , 1 , 0 , 0 , -1 , -1 , -1};
    typedef pair<int , int> PII;
    int n , m;
    int bfs(int px , int py , vector<vector<int>> &land){
        queue <PII> q;
        q.push({px , py});
        land[px][py] = 1;
        int cnt = 1;
        while(!q.empty()){
            auto [x , y] = q.front();
            q.pop();
            for (int i = 0;i < 8;i++){
                int dx = x + DX[i] , dy = y + DY[i];
                if (dx >= 0 && dy >= 0 && dx < n && dy < m && !land[dx][dy]){
                    cnt++;
                    land[dx][dy] = 1;
                    q.push({dx,dy});
                }
            }
        }
        return cnt;
    }
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector <int> ans;
        n = land.size() , m = land[0].size();
        for (int i = 0;i < n;i++){
            for (int j = 0;j < m;j++){
                if (!land[i][j]) ans.push_back(bfs(i , j , land));
            }
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};