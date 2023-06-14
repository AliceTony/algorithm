class Solution {
public:
    int myAtoi(string s) {
        int now = 0 , n = s.size();
        long long ans = 0;
        bool ok = 1;
        for (;now < n && s[now] == ' ';now++);
        if (now == n) return 0;
        if (s[now] == '-')now++ , ok = 0;
        else if (s[now] == '+')now++;
        for (;now < n;now++){
            if (s[now] >= '0' && s[now] <= '9'){
                ans = ans * 10 + s[now] - '0';
                if (ans > INT_MAX) break;
            }
            else break;
        }
        if (ok) return min(ans , (long long)INT_MAX);
        else return max(ans * - 1 , (long long)(INT_MIN));
    }
};