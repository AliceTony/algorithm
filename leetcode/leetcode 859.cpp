class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return 0;
        int arr[26];
        memset(arr , 0 , sizeof(arr));
        int cnt = 0 , first = 0 , second = 0 , n = s.size();
        for(int i = 0;i < n;i++){
            arr[s[i] - 'a']++;
            if (s[i] != goal[i]){
                if (cnt)second = i;
                else first = i;
                cnt++;
            }
        }
        if (cnt > 2 || cnt == 1)return 0;
        if (cnt == 0){
            for (int i = 0;i < 26;i++) if (arr[i] >= 2) return 1;
            return 0;
        }
        if (s[second] == goal[first] && s[first] == goal[second]) return 1;
        else return 0;
    }
};