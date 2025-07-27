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
         if (!head) return nullptr;

        // 1. Clone nodes and interleave them
        Node* curr = head;
        while (curr) {
            Node* clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }

        // 2. Set random pointers
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // 3. Separate the two lists
        curr = head;
        Node* pseudoHead = new Node(0);
        Node* copyCurr = pseudoHead;

        while (curr) {
            copyCurr->next = curr->next;
            curr->next = curr->next->next;

            copyCurr = copyCurr->next;
            curr = curr->next;
        }

        return pseudoHead->next;
    }
};