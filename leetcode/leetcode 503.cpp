class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector <int> res(n, -1);
        vector <int> v;
        for (int i = 0; i < n; i++) {
            while (!v.empty()) {
                if (nums[i] > nums[v.back()]) {
                    res[v.back()] = nums[i];
                    v.pop_back();
                }
                else break;
            }
            v.push_back(i);
        }
        for (int i = 0; i < n; i++) {
            while (!v.empty()) {
                if (nums[i] > nums[v.back()]) {
                    res[v.back()] = nums[i];
                    v.pop_back();
                }
                else break;
            }
        }
        return res;
    }
};