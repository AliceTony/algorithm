class Solution {
private:
    bool check(int n){
        int temp = sqrt(n);
        for (int i = 2;i <= temp;i++){
            if (n % i == 0) return 0; 
        }
        return n > 1;
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size() , ans = 0;
        for (int i = 0;i < n;i++){
            if (check(nums[i][i])) ans = max(nums[i][i] , ans);
            if (check(nums[i][n - i - 1])) ans = max(nums[i][n - i - 1] , ans);
        }
        return ans;
    }
};