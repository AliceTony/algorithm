class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        string str;
        if (numRows == 1) return s;
        for (int i = 0; i < numRows; i++) {
            int add1 = (numRows - 1 - i) * 2;
            int add2 = i * 2;
            bool ok = add1;
            for (int j = i; j < n;) {
                str += s[j];
                if (ok && add1) {
                    j += add1;
                    if (add2) ok = 0;
                }
                else if (!ok && add2) {
                    j += add2;
                    if (add1) ok = 1;
                }
            }
        }
        return str;
    }
};