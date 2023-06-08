class Solution {
private:
    typedef long long ll;
    const int MOD = 1337;
    ll pow(ll x, ll n) {
        ll ans = 1;
        while (n) {
            if (n & 1) ans = ans * x % MOD;
            x = x * x % MOD;
            n >>= 1;
        }
        return ans;
    }
public:
    int superPow(int a, vector<int>& b) {
        ll ans = 1;
        for (ll i : b) {
            ans = pow(ans, 10) * pow(a, i) % MOD;
        }
        return ans;
    }
};