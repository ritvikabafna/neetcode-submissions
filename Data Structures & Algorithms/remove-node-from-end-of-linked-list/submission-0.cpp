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
        if(head->next==NULL && n==1){
            return NULL;
        }
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;

        int size=1;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        temp=dummy;
        int cnt=1;
        n=size-n;
        while(cnt!=n){
            temp=temp->next;
            cnt++;
        }
        if(temp->next->next==NULL)
            temp->next=NULL;
        else{
            ListNode* temp2=temp->next;
            temp->next=temp2->next;
            temp2->next=NULL;
        }
        return dummy->next;
    }
};
