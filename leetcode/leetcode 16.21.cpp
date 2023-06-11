class Solution {
public:
    typedef long long ll;
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        sort(array1.begin() , array1.end());
        sort(array2.begin() , array2.end());
        ll sum1 = 0, sum2 = 0;
        for (int i : array1) sum1 += i;
        for (int i : array2) sum2 += i;
        ll target = sum1 - sum2;
        int n = array1.size() , m = array2.size();
        int l = 0 , r = 0;
        vector <int> ans;
        if (target & 1)return ans;
        while(l < n && r < m){
            int temp = (array1[l] - array2[r]) * 2;
            if (temp == target){
                ans.push_back(array1[l]);
                ans.push_back(array2[r]);
                break;
            }
            else if (temp < target) l++;
            else r++;
        }
        return ans;
    }
};