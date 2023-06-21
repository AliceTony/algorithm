class Solution {
private:
    const int DX[8]{-1 , 0 , 1 , -1 , 1 , -1 , 0 , 1} , DY[8]{1 , 1 ,1 , 0 , 0 , -1 , -1 ,-1};
    typedef pair<int , int> PII;
    bool check(vector <string> &chessboard, int x , int y , int dx , int dy){
        while(x >= 0 && y >= 0 && x < chessboard.size() && y < chessboard[0].size()){
            if (chessboard[x][y] == 'X') return 1;
            else if (chessboard[x][y] == '.') return 0;
            x += dx;
            y += dy;
        }
        return 0;
    }
    int bfs(vector <string> chessboard , int px , int py){
        int cnt = 0;
        queue<PII> q;
        q.push({px , py});
        chessboard[px][py] = 'X';
        while(!q.empty()){
            auto [x , y] = q.front();
            q.pop();
            for (int i = 0;i < 8;i++) {
                int dx = x + DX[i] , dy = y + DY[i];
                if (check(chessboard , dx , dy , DX[i] , DY[i])){
                    while(chessboard[dx][dy] != 'X'){
                        chessboard[dx][dy] = 'X';
                        q.push({dx , dy});
                        dx += DX[i];
                        dy += DY[i];
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
public:
    int flipChess(vector<string>& chessboard) {
        int ans = 0;
        for (int i = 0;i < chessboard.size();i++){
            for (int j = 0;j < chessboard[0].size();j++){
                if (chessboard[i][j] == '.') ans = max(ans , bfs(chessboard , i , j));
            }
        }
        return ans;
    }
};