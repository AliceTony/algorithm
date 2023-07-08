class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0;i < n;i++){
            int l = i + 1 , r = n;
            while(l + 1 < r){
                int mid = (l + r) >> 1;
                if (numbers[i] + numbers[mid] <= target) l = mid;
                else r = mid;
            }
            if (numbers[i] + numbers[l] == target) return {i + 1, l + 1};
        }
        return {0 , 0};
    }
};