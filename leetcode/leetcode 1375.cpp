class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n = flips.size() , minx = 0 , maxn = 0 , ans = 0;
        vector <bool> vis (n + 1, 0);
        for (int i = 0;i < n;i++){
            vis[flips[i] - 1]  = 1;
            if (minx <= flips[i] - 1) for (;minx < n && vis[minx];minx++);
            maxn = max(maxn , flips[i] - 1);
            if (minx - 1 == maxn) ans++;
        }
        return ans;
    }
};