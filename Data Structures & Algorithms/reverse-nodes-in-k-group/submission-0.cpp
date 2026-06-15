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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        ListNode* temp=head;
        for(int i=0;i<k;i++){
            if(temp==NULL)
                return head;
            temp=temp->next;
           
        }
        ListNode* curr=head;
        ListNode* ans=curr;
        ListNode* prev=NULL;
        int cnt=0;
        while(cnt<k){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
        
    }
};
