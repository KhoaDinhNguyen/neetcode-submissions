/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);

        Node* curr = head, *copy = &dummy;
        unordered_map<Node*, Node*> mp;

        while (curr != nullptr) {
            copy->next = new Node(curr->val);
            copy = copy->next;
            mp[curr] = copy;
            curr = curr->next;
        }

        curr = head;

        while (curr != nullptr) {
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }

       
        return dummy.next;
    }
};
