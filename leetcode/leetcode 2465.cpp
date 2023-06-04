class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set <double> ans;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            ans.insert((nums[l] + nums[r]) / 2.0);
            l++, r--;
        }
        return ans.size();
    }
};