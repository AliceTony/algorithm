class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> vis(dictionary.begin(), dictionary.end());
        int f[n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1] + 1;
            for (int j = 0; j < i; j++) {
                if (vis.count(s.substr(j, i - j))) {
                    f[i] = min(f[i], f[j]);
                }
            }
        }
        return f[n];
    }
};