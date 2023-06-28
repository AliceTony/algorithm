class Solution {
public:
    void sortColors(vector<int>& nums) {
        int arr[3]{} , now = 0;
        for (int i : nums)arr[i]++;
        for (int i = 0;i < nums.size();i++){
            if (arr[now]--) nums[i] = now;
            else now++ , i--;
        }
    }
};