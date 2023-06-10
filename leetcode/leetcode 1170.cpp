class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = words.size();
        vector <int> vis(n);
        int arr[26];
        for (int i = 0;i < n;i++){
            memset(arr , 0 , sizeof(arr));
            for (char j : words[i]) arr[j - 'a']++;
            for (int j = 0;j < 26;j++){
                if (arr[j]){
                    vis[i] = arr[j];
                    break; 
                }
            }
        }
        sort(vis.begin() , vis.end());
        vector <int> ans;
        for (int i = 0;i < queries.size();i++){
            memset(arr, 0 , sizeof(arr));
            for (char j : queries[i]) arr[j - 'a']++;
            int cnt = 0;
            for (int j = 0;j < 26;j++){
                if (arr[j]){
                    cnt = arr[j];
                    break;
                }
            }
            int l = -1 , r = n;
            while(l + 1 < r){
                int mid = (l + r) >> 1;
                if (vis[mid] <= cnt) l = mid;
                else r = mid;
            }
            ans.push_back(n - r);
        }
        return ans;
    }
};