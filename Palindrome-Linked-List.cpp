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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head, *fast=head , *prev=NULL ;

         while(fast&&fast->next){
            prev= slow ;
            slow=slow->next ;
            fast= fast->next->next ;
         }
      prev= NULL ;

      ListNode *curr= slow, *fut=slow ;
      
      while(curr){
         fut=curr->next ;
         curr->next= prev;
         prev= curr ;
           curr= fut ;
         
      }
    
    ListNode *curr2= prev , *curr1= head ;

    while(curr1&&curr2){
        if(curr1->val!=curr2->val)
            return false ;
        else
        {
            curr1= curr1->next ;
            curr2= curr2->next ;

        }
    }

return true ;

    }
};