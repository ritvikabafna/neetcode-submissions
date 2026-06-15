class Node{
    public:
    int val;
    int key;
    Node* next;
    Node* prev;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        prev=NULL;
        next=NULL;
    }
};

class LRUCache {
public:
    unordered_map<int,Node*>m;
    Node* head;
    Node* tail;
    int capacity;
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    void solve(Node* temp){
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;

            temp->prev=tail->prev;
            temp->next=tail;
            tail->prev->next=temp;
            tail->prev=temp;
    }
    int get(int key) {
        auto it=m.find(key);
        if(it==m.end())
            return -1;
        else{
            solve(m[key]);
            return m[key]->val;
        }

    }

    void put(int key, int value) {
        auto it=m.find(key);
        if(it!=m.end()){
            m[key]->val=value;
            solve(m[key]);
            return;
        }
        Node* temp=new Node(key,value);
        if(m.size()==capacity){
            Node* lru = head->next;
            head->next = lru->next;
            lru->next->prev = head;
            m.erase(lru->key);
        }

        tail->prev->next = temp;
        temp->prev = tail->prev;

        temp->next = tail;
        tail->prev = temp;

        m[key]=temp;
    }
};
