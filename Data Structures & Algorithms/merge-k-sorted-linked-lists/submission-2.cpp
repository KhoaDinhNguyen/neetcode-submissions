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
        if (lists.empty()) return nullptr;

        auto cmp = [](ListNode* a, ListNode* b) {return a->val > b->val; };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        for (ListNode* l: lists) {
            if (l != nullptr) {
                minHeap.push(l);
            }
        }

        ListNode dummy(0), *curr = &dummy;

        while (!minHeap.empty()) {
            ListNode* minNode = minHeap.top();
            minHeap.pop();

            curr->next = minNode;
            curr = curr->next;

            minNode = minNode->next;

            if (minNode != nullptr) {
                minHeap.push(minNode);
            }
        }

        return dummy.next;

    }
};
