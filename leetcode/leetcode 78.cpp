class Solution {
private:
    vector <vector <int>> ans;
    vector <bool> vis;
    void dfs(vector <int> &arr , vector <int> &nums ,int now) {
        ans.push_back(arr);
        for (int i = now;i < nums.size();i++){
            arr.push_back(nums[i]);
            vis[i] = 1;
            dfs(arr,nums,i + 1);
            vis[i] = 0;
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> arr;
        vis.resize(nums.size() + 1);
        dfs(arr , nums , 0);
        return ans;
    }
};