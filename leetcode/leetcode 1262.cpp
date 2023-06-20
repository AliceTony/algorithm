class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector <int> arr[3];
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i : nums){
            arr[i % 3].push_back(i);
            sum += i;
        }
        if (sum % 3 == 0) return sum;
        else if (sum % 3 == 1){
            int temp1 = INT_MAX , temp2 = INT_MAX;
            if (arr[1].size()) temp1 = arr[1][0];
            if (arr[2].size() >= 2) temp2 = arr[2][0] + arr[2][1];
            sum -= min(temp1 , temp2);
        }
        else if (sum % 3 == 2){
            int temp1 = INT_MAX , temp2 = INT_MAX;
            if(arr[2].size()) temp1 = arr[2][0];
            if (arr[1].size() >= 2) temp2 = arr[1][0] + arr[1][1];
            sum -= min(temp1 , temp2);
        }
        return sum;
    }
};