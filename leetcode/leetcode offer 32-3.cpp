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
    typedef pair<TreeNode* , int> PTI;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> ans;
        if (!root) return ans;
        queue<PTI> q;
        q.push({root , 0});
        int now = 0;
        vector <int> temp;
        while(!q.empty()){
            PTI t = q.front();
            q.pop();
            if (t.second > now){
                if (now & 1)reverse(temp.begin() , temp.end());
                now = t.second;
                ans.push_back(move(temp));
            }
            temp.push_back(t.first->val);
            if (t.first->left)q.push({t.first->left , now + 1});
            if (t.first->right)q.push({t.first->right , now + 1});
        }
        if (now & 1)reverse(temp.begin() , temp.end());
        ans.push_back(move(temp));
        return ans;
    }
};