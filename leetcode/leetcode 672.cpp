class Solution {
public:
    int flipLights(int n, int presses) {
        unordered_set <int> s;
        for (int i = 0; i < 16; i++) {
            int vis[4];
            int cnt = 0;
            for (int j = 0; j < 4; j++) vis[j] = (i >> j) & 1, cnt += vis[j];
            if (cnt <= presses && !((presses - cnt) & 1)) {
                int ans = vis[0] ^ vis[2] ^ vis[3];
                if (n >= 2) {
                    ans |= (vis[0] ^ vis[1]) << 1;
                }
                if (n >= 3) {
                    ans |= (vis[0] ^ vis[2]) << 2;
                }
                if (n >= 4) {
                    ans |= (vis[0] ^ vis[1] ^ vis[3]) << 3;
                }
                s.emplace(ans);
            }
        }
        return s.size();
    }
};