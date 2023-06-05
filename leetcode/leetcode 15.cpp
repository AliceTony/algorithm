class Solution {

public:
    struct
        vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector <vector <int>> ans;
        for (int i = 0; i < n - 2; i++) {
            while (i&& i < n&& nums[i] == nums[i - 1]) i++;
            for (int j = i + 1, k = n - 1; k > j;) {
                while (k > j && nums[i] + nums[j] > -nums[k]) k--;
                while (j < k && nums[i] + nums[j] < -nums[k]) j++;
                if (j >= k) break;
                if (nums[i] + nums[j] == -nums[k]) {
                    ans.push_back({ nums[i] , nums[j] , nums[k] });
                    k--;
                    j++;
                    while (k < n - 1 && k > j && nums[k] == nums[k + 1]) k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                }
                else {
                    k--;
                }

            }
        }
        return ans;
    }
};