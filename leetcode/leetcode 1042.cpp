class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector <int> E[n];
        for (auto i : paths){
            E[i[0] - 1].push_back(i[1] - 1);
            E[i[1] - 1].push_back(i[0] - 1);
        }
        vector <int> ans(n , 0);
        for (int i = 0;i < n;i++){
            vector <bool> vis(5 , 0);
            for (int v : E[i]) vis[ans[v]] = 1;
            for (int j = 1;j <= 4;j++){
                if (!vis[j]) {
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};