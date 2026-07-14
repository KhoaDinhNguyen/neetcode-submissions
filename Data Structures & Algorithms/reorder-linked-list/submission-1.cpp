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
    void printList(ListNode* head) {
        while (head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }

        cout << endl;
    }
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

    void reorderList(ListNode* head) {
        ListNode* slow = head, *fast = head, *preSlow = NULL;

        do {
            preSlow = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast == NULL) break;
            fast = fast->next;
        }
        while(fast != NULL);
        
        ListNode* list1 = head, *list2 = reverseList(slow);
        preSlow->next = NULL;

        ListNode dummy(0), *curr = &dummy;

        while (list1 != NULL && list2 != NULL) {
            ListNode* next1 = list1->next, *next2 = list2->next;
            curr->next = list1;
            curr->next->next = list2;
            curr = curr->next->next;
            list1 = next1;
            list2 = next2;
        }

        if (list1 != NULL) {curr->next = list1; curr->next->next = NULL;} 

        printList(dummy.next);
    }
};
