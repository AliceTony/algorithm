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
bool dfs(TreeNode* p , TreeNode* q){
    if (p->left){
        if (q->left){
            if (p->left->val != q->left->val || !dfs(p->left , q->left)) return 0;
        }
        else return 0;
    }
    else if (q->left) return 0;
    if (p->right){
        if (q->right){
            if (p->right->val != q->right->val || !dfs(p->right , q->right)) return 0;
        }
        else return 0;
    }
    else if (q->right) return 0;
    return 1;
}
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return 1;
        if ((p != nullptr && q == nullptr) || (p == nullptr && q != nullptr) || p->val != q->val) return 0;
        return dfs(p , q);
    }
};