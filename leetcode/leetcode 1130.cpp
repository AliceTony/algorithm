class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int ans = 0;
        vector <int> v;
        for (int i : arr) {
            while (!v.empty() && v.back() < i) {
                int t = v.back();
                v.pop_back();
                if (v.empty() || v.back() > i) ans += t * i;
                else ans += v.back() * t;
            }
            v.push_back(i);
        }
        while (v.size() >= 2) {
            int t = v.back();
            v.pop_back();
            ans += v.back() * t;
        }
        return ans;
    }
};