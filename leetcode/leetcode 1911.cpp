class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long odd = 0, ans = 0;
        for (int i : nums){
            long long temp = max(odd , ans - i);
            ans = max(ans , odd + i);
            odd = temp;
        }
        return ans;
    }
};