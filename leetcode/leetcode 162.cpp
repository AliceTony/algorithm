class Solution {
private:
    bool check(int mid, vector <int>& nums) {
        if (mid == 0 || nums[mid] > nums[mid - 1]) return 1;
        return 0;
    }
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size();
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (check(mid, nums))l = mid;
            else r = mid;
        }
        return l;
    }
};