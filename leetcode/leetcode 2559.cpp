class Solution {
private:
    inline bool check(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
        else return 0;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector <int> sum(n + 1);
        sum[0] = 0;
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + (check(words[i][0]) && check(words[i].back()));
        }
        vector <int> ans;
        n = queries.size();
        ans.reserve(n);
        for (int i = 0; i < n; i++) {
            ans.push_back(sum[queries[i][1] + 1] - sum[queries[i][0]]);
        }
        return ans;
    }
};