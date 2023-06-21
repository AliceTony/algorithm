/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool check(TreeNode *A, TreeNode* B){
        queue<TreeNode *>qa;
        qa.push(A);
        queue<TreeNode *>qb;
        qb.push(B);
        while(!qa.empty()){
            TreeNode *ta = qa.front();
            TreeNode *tb = qb.front();
            qa.pop();
            qb.pop();
            if (tb->left){
                if (ta->left){
                    if (ta->left->val == tb->left->val) qa.push(ta->left) , qb.push(tb->left);
                    else return 0;
                }
                else return 0;
            }
            if (tb->right){
                if (ta->right){
                    if (ta->right->val == tb->right->val) qa.push(ta->right) , qb.push(tb->right);
                    else return 0;
                }
                else return 0;
            }
        }
        return 1;
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) return 0;
        queue <TreeNode *> q;
        q.push(A);
        while(!q.empty()){
            TreeNode *t = q.front();
            q.pop();
            if (t->val == B->val && check(t , B)) return 1;
            if (t->left)q.push(t->left);
            if (t->right)q.push(t->right);
        }
        return 0;
    }
};