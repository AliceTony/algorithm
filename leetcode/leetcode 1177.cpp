class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int sum[n + 1][26];
        memset(sum , 0 ,sizeof(sum));
        for (int i = 0;i < n;i++){
            sum[i + 1][s[i] - 'a']++;
            for (int j = 0;j < 26;j++) sum[i + 1][j] += sum[i][j];
        }
        vector <bool> ans;
        ans.reserve(queries.size());
        for (auto& i : queries){
            i[2] *= 2;
            if ((i[1] - i[0] + 1) & 1)i[2]++;
            for (int j = 0;j < 26;j++){
                if ((sum[i[1] + 1][j] - sum[i[0]][j]) & 1)i[2]--;
            }
            if (i[2] < 0) ans.push_back(0);
            else ans.push_back(1);
        }
        return ans;
    }
};