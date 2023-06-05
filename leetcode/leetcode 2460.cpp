class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int now = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i]) {
                nums[now++] = nums[i];
            }
        }
        while (now < n) nums[now++] = 0;
        return nums;
    }
};