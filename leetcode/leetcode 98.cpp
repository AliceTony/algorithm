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
    typedef long long ll;
    bool dfs(TreeNode* root , ll l , ll r){
        if (root->val < l || root->val > r) return 0;
        if (root->left && !dfs(root->left, l , ll(root->val - 1ll))) return 0;
        if (root->right && !dfs(root->right , ll(root->val + 1ll), r)) return 0;
        return 1;
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root , INT_MIN , INT_MAX);
    }
};