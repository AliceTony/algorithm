class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int f[3]{}, res = arr[0] , n = arr.size() , ans;
        if (n == 1) return arr[0];
        if (n == 2) return max(max(arr[0] , arr[0] + arr[1]) , arr[1]);
        f[0] = arr[0];
        f[1] = max(arr[0] + arr[1] , arr[1]);
        ans = f[1];
        for (int i = 2;i < n;i++){
            f[2] = max(f[1] + arr[i], arr[i]);
            res = max(res + arr[i], f[0] + arr[i]);
            f[0] = f[1];
            f[1] = f[2];
            ans = max(max(res , ans) , f[2]);            
        }
        return ans;
    }
};