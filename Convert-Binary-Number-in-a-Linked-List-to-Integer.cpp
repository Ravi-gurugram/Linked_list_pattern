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
    int getDecimalValue(ListNode* head) {
        ListNode* temp= head ;
        vector<int>ans ;
        while(temp){
            ans.push_back(temp->val) ;
            temp= temp->next ; 
           }
        if(ans.size()==0)
            return 0 ;
        int sum=0;
        int i=0 , j= ans.size()-1 ;

        while(j>=0){
            sum+= ans[j] * pow(2,i) ;
            j--;i++ ;
        }

return sum ;

    }
};