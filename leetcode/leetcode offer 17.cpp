class Solution {
public:
    vector<int> printNumbers(int n) {
        int math = pow(10 , n);
        vector <int> ans;
        ans.reserve(math);
        for (int i = 1;i < math;i++) ans.push_back(i);
        return ans;
    }
};