class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) continue;
                int l = j, r = n;
                while (l + 1 < r) {
                    int mid = (l + r) >> 1;
                    if (nums[mid] <= nums[j]) l = mid;
                    else r = mid;
                }
                ans += n - r;
            }
        }
        return ans;
    }
};