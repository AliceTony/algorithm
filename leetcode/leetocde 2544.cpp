class Solution {
public:
    int alternateDigitSum(int n) {
        string str = to_string(n);
        int ans = 0, temp = 1;
        for (char i : str) {
            ans += (i - '0') * temp;
            temp *= -1;
        }
        return ans;
    }
};