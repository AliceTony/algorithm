class Solution {
private:
    int ans = 0;
    int n;
    void dfs(int x , vector <bool> &vis , int num){
        if (x % num == 0 || num % x == 0){
            if (num == n) {
                ans++;
                return;
            }
            for (int i = 1;i <= n;i++){
                if (!vis[i]){
                    vis[i] = 1;
                    dfs(i , vis , num + 1);
                    vis[i] = 0;
                }
            }
        }
    }
public:
    int countArrangement(int n) {
        Solution::n = n;
        vector <bool> vis(n , 0);
        for (int i = 1;i <= n;i++){
            vis[i] = 1;
            dfs(i , vis , 1);
            vis[i] = 0;
        }
        return ans;
    }
};