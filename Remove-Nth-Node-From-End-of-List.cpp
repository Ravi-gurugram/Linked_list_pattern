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
         ListNode* dummy = new ListNode(0, head);  // Handle edge cases
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        // Move both until fast reaches the end
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove nth node
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return dummy->next;
    }
};