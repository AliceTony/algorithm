class Solution {
public:
    string longestPalindrome(string s) {
        int len1 = s.size();
        int len2 = len1 * 2 + 2;
        string str(len2 + 1, '0');
        str[0] = '$';
        str[1] = '#';
        for (int i = 0; i < len1; i++) {
            str[2 * i + 2] = s[i];
            str[2 * i + 3] = '#';
        }
        str[len2] = '*';
        vector <int> p(len2 + 1, 1);
        int mx = 0, id = 0;
        for (int i = 1; i < len2; i++) {
            if (mx > i) p[i] = min(p[2 * id - i], mx - i);
            while (str[i + p[i]] == str[i - p[i]]) p[i]++;
            if (mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
        }
        int cnt = 0;
        id = 0;
        for (int i = 0; i < len2; i++) {
            if (cnt < p[i]) {
                cnt = p[i];
                id = i;
            }
        }
        id = (id - 2) / 2;
        cnt--;
        string ans;
        if (cnt & 1) ans = s.substr(id - cnt / 2, cnt);
        else ans = s.substr(id - cnt / 2 + 1, cnt);
        return ans;
    }
};