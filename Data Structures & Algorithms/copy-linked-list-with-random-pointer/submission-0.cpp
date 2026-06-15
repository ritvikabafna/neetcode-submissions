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
        if (head==NULL)
            return NULL;
        Node* tail=head;
        while(tail!=NULL){
            Node* copy=new Node(tail->val);
            Node* temp=tail->next;
            tail->next=copy;
            copy->next=temp;
            tail=tail->next->next;
        }
        tail=head;
        Node* copy=tail->next;
        while(tail!=NULL){
            if(tail->random==NULL){
                copy->random=NULL;
            }
            else{
            copy->random=tail->random->next;
            }
            tail=tail->next->next;
            copy=copy->next->next;
        }
        tail=head;
        copy=tail->next;
        Node* ans=copy;
        while(tail!=NULL){
            tail->next=copy->next;
            tail=tail->next;
            if(tail!=NULL)
            copy->next=tail->next;
            copy=copy->next;
        }
        
        return ans;
    }
};
