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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        else if (head->next == NULL) return head;
        
        ListNode *fi = head, *se = head->next, *th = head->next->next;

        fi->next = NULL;
        while (th != NULL) {
            se->next = fi;
            fi = se;
            se = th;
            th = th->next;
        }

        se->next = fi;
        head = se;
        
        return head;
    }
};
