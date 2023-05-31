class Solution {
public:
    int findComplement(int num) {
        long long ans = 1;
        int temp = num;
        while (temp) {
            ans <<= 1;
            temp >>= 1;
        }
        return ans - num - 1;
    }
};