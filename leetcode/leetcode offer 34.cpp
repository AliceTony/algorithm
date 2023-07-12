/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector <vector <int>> ans;
    void dfs(TreeNode* root, vector <int>& temp, int sum, int target) {
        temp.push_back(root->val);
        sum += root->val;
        if (root->left) dfs(root->left, temp, sum, target);
        if (root->right) dfs(root->right, temp, sum, target);
        if (sum == target && !root->left && !root->right) ans.push_back(temp);
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if (!root) return ans;
        vector <int> temp;
        dfs(root, temp, 0, target);
        return ans;
    }
};