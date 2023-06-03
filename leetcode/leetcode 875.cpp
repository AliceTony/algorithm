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
    ListNode* middleNode(ListNode* head) {
        int cnt = 1;
        ListNode* last = head;
        while (last->next != nullptr)last = last->next, cnt++;
        int mid = cnt / 2 + 1;
        for (int i = 0; i < mid - 1; i++) head = head->next;
        return head;
    }
};