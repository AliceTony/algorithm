class Solution {
public:
    string minNumber(vector<int>& nums) {
        string ans;
        vector <string> strs;
        strs.reserve(nums.size());
        for (int i : nums) strs.push_back(to_string(i));
        sort(strs.begin() , strs.end() , [](string& x, string& y){ return x + y < y + x; });
        for (string i : strs) ans += i;
        return ans;
    }
};