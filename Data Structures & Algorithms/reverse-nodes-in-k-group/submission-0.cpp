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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy = ListNode(0, head);
        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kthNode = getKthNode(groupPrev, k);
            if (!kthNode) break;

            ListNode* groupNext = kthNode->next;

            // reverse group
            ListNode* prev = kthNode->next, *curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            ListNode* tmp = groupPrev->next;
            groupPrev->next = kthNode;
            groupPrev = tmp;
        }

        return dummy.next;
    }

    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr != nullptr && k > 0) {
            curr = curr->next;
            k--;
        }

        return curr;
    }
};
