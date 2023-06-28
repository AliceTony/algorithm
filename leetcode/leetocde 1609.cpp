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
    typedef pair <TreeNode *, int> PTI;
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<PTI> q;
        q.push({root, 1});
        int now = 0 , temp = 0;
        while(!q.empty()){
            PTI t = q.front();
            q.pop();
            if (t.second == now + 1){
                temp = t.first->val;
                now = t.second;
                if (now & 1){
                    if (!(temp & 1)) return 0;
                }
                else {
                    if (temp & 1) return 0;
                }
            }
            else {
                if (now & 1){
                    if (t.first->val > temp && t.first->val & 1) temp = t.first->val;
                    else return 0;
                }
                else {
                    if (t.first->val < temp && !(t.first->val & 1)) temp = t.first->val;
                    else return 0;
                }
            }
            if (t.first->left) q.push({t.first->left , now + 1});
            if (t.first->right) q.push({t.first->right , now + 1});
        }
        return 1;
    }
};