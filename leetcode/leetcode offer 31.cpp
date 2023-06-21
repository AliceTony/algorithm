class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int l = 0 , r = 0;
        vector <int> ans;
        int n = pushed.size();
        while(l < n){
            ans.push_back(pushed[l++]);
            while(!ans.empty() && ans.back() == popped[r])ans.pop_back() , r++;
        }
        return ans.empty();
    }
};