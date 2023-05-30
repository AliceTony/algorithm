class Solution {
private:
    void check(string s, int i, vector <string>& ans) {
        if (i == s.size()) return;
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 'a' + 'A';
            ans.push_back(s);
            check(s, i + 1, ans);
            s[i] = s[i] - 'A' + 'a';
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
            ans.push_back(s);
            check(s, i + 1, ans);
            s[i] = s[i] - 'a' + 'A';
        }
        check(s, i + 1, ans);
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector <string> ans;
        ans.push_back(s);
        check(s, 0, ans);
        return ans;
    }
};