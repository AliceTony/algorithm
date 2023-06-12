class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0 , ans = 0;
        for (char i : s){
            if (i == ' '){
                if (cnt) ans = cnt;
                cnt = 0;
            }
            else cnt++;
        }
        if (cnt) return cnt;
        else return ans;
    }
};