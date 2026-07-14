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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int len = 0;

        while (curr != NULL) {
            curr = curr->next;
            len++;
        }

        int k = len - n;

        if (k == 0) return head->next;

        curr = head;

        while (k > 1) {
            curr = curr->next;
            k--;
        }

        curr->next = curr->next->next;

        return head;
    }
};
