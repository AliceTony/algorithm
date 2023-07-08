class Solution {
private:
    vector <vector <int>> ans;
    void dfs(int n , int target , vector <int> &candidates , vector <int> &nums){
        if (n == target){
            ans.push_back(nums);
            return;
        }
        for (int i : candidates){
            if (n + i > target) return;
            if (i < nums.back()) continue;
            nums.push_back(i);
            dfs(n + i , target , candidates , nums);
            nums.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector <int> nums;
        for (int i : candidates){
            nums.push_back(i);
            dfs(i , target , candidates , nums);
            nums.pop_back();
        }
        return ans;
    }
};