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

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = new TreeNode(preorder[0]);
        for (int i = 1;i < preorder.size();i++){
            TreeNode *parent = root;
            while(1){
                if (preorder[i] > parent->val){
                    if (parent->right) parent = parent->right;
                    else {
                        parent->right = new TreeNode(preorder[i]);
                        break;
                    }
                }
                else{
                    if (parent->left) parent = parent->left;
                    else {
                        parent->left = new TreeNode(preorder[i]);
                        break;
                    }
                }
            }
        }
        return root;
    }
};