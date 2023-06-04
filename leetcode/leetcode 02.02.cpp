/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode* last = head;
        int cnt = 0;
        while (last != nullptr)last = last->next, cnt++;
        cnt -= k;
        while (cnt--) head = head->next;
        return head->val;
    }
};