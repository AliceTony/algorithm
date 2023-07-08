class Solution {
private:
    vector <vector <int>> ans;
    void dfs(int sum , int n , int target , vector <int> &candidates , vector <int> &nums){
        if (sum == target){
            ans.push_back(nums);
            return;
        }
        for (int i = n;i < candidates.size();){
            if (sum + candidates[i] > target) return;
            nums.push_back(candidates[i]);
            dfs(sum + candidates[i] , i + 1, target , candidates , nums);
            nums.pop_back();
            i++;
            while (i < candidates.size() && candidates[i] == candidates[i - 1]) i++;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector <int> nums;
        for (int i = 0;i < candidates.size();){
            nums.push_back(candidates[i]);
            dfs(candidates[i] , i + 1, target , candidates , nums);
            nums.pop_back();
            i++;
            while (i < candidates.size() && candidates[i] == candidates[i - 1]) i++;
        }
        return ans;
    }
};