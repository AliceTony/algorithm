class Solution {
public:
    typedef pair<int, int> PII;
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        int ans = 0;
        vector <int> vis;
        vis.reserve(n);
        for (int i = 0; i < n; i++) vis.push_back(reward1[i] - reward2[i]), ans += reward2[i];
        sort(vis.begin(), vis.end());
        for (int i = n - 1; k; i--, k--) ans += vis[i];
        return ans;
    }
};