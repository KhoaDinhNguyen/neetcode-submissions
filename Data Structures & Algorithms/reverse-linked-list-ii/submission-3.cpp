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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr) return head;
    
        vector<ListNode*> l;

        int i = 1;

        ListNode* curr = head;

        if (left == 1) l.push_back(nullptr);
        
        while (curr != nullptr) {
            if (left - 1 <= i && i <= right + 1) {
                l.push_back(curr);
            }

            curr = curr->next;
            i++;
        }

        if (i - 1 == right) l.push_back(nullptr);
    
        int N = l.size();

        ListNode* lastNode = l[N - 1];
        ListNode* firstNode = l[0];
        for (int i = N - 2; i >= 1; --i) {
            if (l[i] != nullptr) {
                l[i]->next = l[i - 1]; 
            }
        }

        l[1]->next = lastNode;
        if (firstNode == nullptr) {
            head = l[N - 2];
        }
        else {
            l[0]->next = l[N - 2];
        }



        return head;
    }
};