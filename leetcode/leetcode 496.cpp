class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map <int, int> mark;
        for (int i = 0; i < n; i++) mark[nums1[i]] = i;
        vector <int> res(n, -1);
        stack <int> st;
        for (int i : nums2) {
            while (!st.empty()) {
                if (i > st.top()) {
                    if (mark.count(st.top())) res[mark[st.top()]] = i;
                    st.pop();
                }
                else break;
            }
            st.push(i);
        }
        return res;
    }
};