class Solution {
private:
    typedef pair <int, int> PII;
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        if (n == 1) return 1;
        vector <PII> vis[26];
        for (int i = 0; i < n;) {
            if (i == n - 1) {
                vis[text[i] - 'a'].push_back({ i , i + 1 });
                break;
            }
            for (int j = i + 1; j < n; j++) {
                if (text[j] != text[i]) {
                    vis[text[i] - 'a'].push_back({ i , j });
                    i = j;
                    break;
                }
                if (j == n - 1) {
                    vis[text[i] - 'a'].push_back({ i , j + 1 });
                    i = j + 1;
                    break;
                }
            }
        }
        int ans = 1;
        for (int i = 0; i < 26; i++) {
            if (vis[i].empty()) continue;
            ans = max(ans, vis[i][0].second - vis[i][0].first + (vis[i].size() >= 2));
            for (int j = 1; j < vis[i].size(); j++) {
                if (vis[i][j - 1].second == vis[i][j].first - 1) {
                    ans = max(ans, vis[i][j].second - vis[i][j - 1].first + ((vis[i].size() >= 3) ? 0 : -1));
                }
                else {
                    ans = max(ans, vis[i][j].second - vis[i][j].first + 1);
                }
            }
        }
        return ans;
    }
};