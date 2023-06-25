class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long sum = 0 , ans = 1e9;
        int n = nums.size();
        for  (int i = 0 , j = 0;j < n;j++){
            sum += nums[j];
            while(sum - nums[i] >= target){
                sum -= nums[i];
                i++;
            }
            if (sum >= target)ans = ans > j - i + 1 ? j - i + 1 : ans;
        }
        if (ans == 1e9) return 0;
        else return ans;
    }
};