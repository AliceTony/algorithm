class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string str;
        int ans = 0;
        unordered_set<char> vis;
        for (char i : s){
            if (vis.insert(i).second) str += i;
            else {
                ans = max((int)str.size() , ans);
                for (int j = 0;j < str.find(i);j++) vis.erase(str[j]);
                str = str.substr(str.find(i) + 1);
                str += i;
            }
        }
        ans = max((int)str.size() , ans);
        return ans;
    }
};