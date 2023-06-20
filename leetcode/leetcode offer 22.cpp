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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp) temp = temp->next , cnt++;
        cnt -= k;
        while(cnt--) head = head->next;
        return head;
    }
};