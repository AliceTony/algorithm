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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefix = 0;
        unordered_map < int , ListNode* > sum;
        ListNode* ans = new ListNode(0);
        ans->next = head;
        for (ListNode* it = ans;it;it = it->next){
            prefix += it->val;
            sum[prefix] = it->next;
        }
        prefix = 0;
        for (ListNode* it = ans;it;it = it->next){
            prefix += it->val;
            it->next = sum[prefix];
        }
        return ans->next;
    }
};