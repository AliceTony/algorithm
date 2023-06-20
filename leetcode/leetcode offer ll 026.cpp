/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector <ListNode *> ans;
        for (ListNode *it = head;it;it = it->next) ans.push_back(it);
        int l = 0 , r = ans.size() - 1;
        while(l < r){
            ans[l]->next = ans[r];
            ans[r--]->next = ans[++l];
        }
        ans[l]->next = nullptr;
    }
};