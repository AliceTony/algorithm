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
    bool delTree(TreeNode* root, unordered_map <int, bool>& to_del, vector <TreeNode*>& ans) {
        if (to_del.count(root->val)) {
            if (root->left != nullptr && delTree(root->left, to_del, ans)) ans.push_back(root->left);
            if (root->right != nullptr && delTree(root->right, to_del, ans)) ans.push_back(root->right);
            return 0;
        }
        else {
            if (root->left != nullptr && !delTree(root->left, to_del, ans))root->left = nullptr;
            if (root->right != nullptr && !delTree(root->right, to_del, ans)) root->right = nullptr;
            return 1;
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector <TreeNode*> ans;
        unordered_map <int, bool> to_del;
        for (int i : to_delete) to_del[i] = 1;
        if (root == nullptr) return { nullptr };
        if (delTree(root, to_del, ans)) ans.push_back(root);
        return ans;
    }
};