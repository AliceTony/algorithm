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
private:
    ListNode* reverse(ListNode* l, int& cnt) {
        ListNode* temp = l->next;
        if (temp != nullptr) l->next = nullptr;
        while (temp != nullptr) {
            ListNode* tmp = temp->next;
            temp->next = l;
            l = temp;
            temp = tmp;
            cnt++;
        }
        return l;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cnt1 = 1, cnt2 = 1;
        l1 = reverse(l1, cnt1), l2 = reverse(l2, cnt2);
        if (cnt1 < cnt2) swap(l1, l2);
        ListNode* ans = l1;
        int temp = 0;
        while (l2 != nullptr) {
            l1->val += l2->val + temp;
            temp = l1->val / 10;
            l1->val %= 10;
            if (l1->next == nullptr && temp) l1->next = new ListNode(0);
            l1 = l1->next;
            l2 = l2->next;
        }
        while (temp) {
            l1->val += temp;
            temp = l1->val / 10;
            l1->val %= 10;
            if (l1->next == nullptr && temp) l1->next = new ListNode(0);
            l1 = l1->next;
        }
        ans = reverse(ans, cnt1);
        return ans;
    }
};