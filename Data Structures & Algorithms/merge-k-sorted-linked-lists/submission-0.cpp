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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;

        if (lists.empty()) return head;

        int k = lists.size();
        ListNode* headTemp = head;

        while (true) {
            int mark = 0;
            ListNode* curr = nullptr;

            for (int i = 0; i < k; ++i) {
                // lists[i] is null
                if (lists[i] == nullptr) continue;
                // curr is nullptr
                else if (curr == nullptr) {
                    curr = lists[i];
                    mark = i;
                }
                // curr is not null
                else if (curr->val > lists[i]->val) {
                    curr = lists[i];
                    mark = i;
                }
            }
            if (curr == nullptr) return head;
            
            if (head == nullptr) {
                head = curr;
                headTemp = head;
            }
            else {
                headTemp->next = curr;
                headTemp = headTemp->next;
            }
            
            lists[mark] = lists[mark]->next;
        }

        return nullptr;

    }
};
