class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector <int> ans;
        int first = nums[0] , second = INT_MAX;
        for (int i : nums){
            if (i <= first) first = i;
            else if (i <= second) second = i;
            else return 1; 
        }
        return 0;
    }
};