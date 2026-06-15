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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        int carry=0;
        ListNode* temp= new ListNode(-1) ;
        ListNode* temp2=l2;
        temp->next=l1;
        ListNode* ans=l1;
        while(l1!=NULL || l2!=NULL || carry!=0){
            if(temp->next!=NULL)
                    temp=temp->next;
                else {
                    temp->next=temp2;
                    temp=temp->next;
                }
            int sum=carry;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            carry=sum/10;
            int digit=sum%10;
            if(temp!=NULL){
                temp->val=digit;
            }
            
        }
        temp->next=NULL;
        return ans;
    }
};
