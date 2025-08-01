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
        ListNode* prev=NULL;
        ListNode* curr=head; 
        ListNode* fut=head;
        if(fut==NULL)
           return fut;
        while(curr){
            fut=curr->next;
             curr->next=prev;
             prev= curr;
             curr=fut ;
             
        }
        head=prev ;
        return prev ;
    }
};