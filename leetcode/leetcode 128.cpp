class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        sort(nums.begin() , nums.end());
        int ans = 1 , n = nums.size();
        for (int i = 0;i < n - 1;){
            int j = i + 1;
            for(;j < n;j++){
                if (nums[j] == nums[j - 1])i++;
                else if (nums[j] != nums[j - 1] + 1)break;
            }
            ans = max(ans , j - i);
            i = j;
        }
        return ans;
    }
};