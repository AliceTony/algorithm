class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return 0;
        string str = to_string(x);
        int n = str.size();
        for (int i = 0; i < n; i++) {
            if (str[i] != str[n - i - 1])return 0;
        }
        return 1;
    }
};