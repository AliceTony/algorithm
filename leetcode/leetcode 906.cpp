class Solution {
private:
    typedef long long ll;
    bool check(ll temp) {
        string str = to_string(temp);
        bool ok = 1;
        for (int i = 0, j = str.size() - 1; i < j; i++, j--) {
            if (str[i] != str[j]) {
                ok = 0;
                break;
            }
        }
        return ok;
    }
public:
    int superpalindromesInRange(string left, string right) {
        ll l = stoll(left), r = stoll(right);
        int cnt = 0;
        for (int i = 1; i < 10; i++) {
            if (i * i >= l && i * i <= r) cnt += check(i * i);
        }
        const int MAX = 10000;
        for (int x = 1; x < MAX; x++) {
            for (int k = 0; k < 10; k++) {
                string str = to_string(x);
                str += char(k + '0');
                int len = str.size();
                for (int i = len - 2; i >= 0; i--)str += str[i];
                ll temp = stoi(str);
                temp *= temp;
                if (temp > r) break;
                if (temp < l) continue;
                cnt += check(temp);
            }
            string str = to_string(x);
            int len = str.size();
            for (int i = len - 1; i >= 0; i--)str += str[i];
            ll temp = stoi(str);
            temp *= temp;
            if (temp > r) break;
            if (temp < l) continue;
            cnt += check(temp);
        }
        return cnt;
    }
};