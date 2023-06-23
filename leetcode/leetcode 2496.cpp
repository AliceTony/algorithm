class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for (string i : strs){
            bool ok = 1;
            int temp = 0;
            for (char j : i){
                if (isdigit(j)) temp = temp * 10 + j - '0';
                else {
                    ok = 0;
                    break;
                }
            }
            if (ok) ans = max(ans, temp);
            else ans = max(ans, (int)(i.size()));
        }
        return ans;
    }
};