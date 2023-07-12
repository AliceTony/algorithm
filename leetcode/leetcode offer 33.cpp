class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        vector <int> v;
        int parent = INT_MAX;
        for (int i = postorder.size() - 1; i >= 0; i--) {
            if (postorder[i] >= parent) return 0;
            while (!v.empty() && v.back() > postorder[i]) {
                parent = v.back();
                v.pop_back();
            }
            v.push_back(postorder[i]);
        }
        return 1;
    }
};