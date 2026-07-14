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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0), *curr = &dummy;

        int carry = 0, val = 0;
        while (l1 != NULL && l2 != NULL) {
            val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) >= 10? 1: 0;

            curr->next = new ListNode(val);
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL) {
            val = (l1->val + carry) % 10;
            carry = (l1->val + carry) >= 10? 1: 0;
            curr->next = new ListNode(val);
            curr = curr->next;
            l1 = l1->next;
        }

        while (l2 != NULL) {
            val = (l2->val + carry) % 10;
            carry = (l2->val + carry) >= 10? 1: 0;
            curr->next = new ListNode(val);
            curr = curr->next;
            l2 = l2->next;
        }

        if (carry == 1) curr->next = new ListNode(1);

        return dummy.next;
    }
};
