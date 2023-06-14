class Solution {
public:
    const int MOD = 1e9 + 7;
    typedef long long ll;
    int countHomogenous(string s) {
        ll cnt = 0 , n = s.size() , now = 1;
        for (int i = 1;i < n;i++){
            if (s[i] == s[i - 1])now++;
            else {
                cnt = (cnt + (now * (now + 1)) / 2) % MOD;
                now = 1;
            }
        }
        cnt = (cnt + now * (now + 1) / 2) % MOD;
        return cnt;
    }
};