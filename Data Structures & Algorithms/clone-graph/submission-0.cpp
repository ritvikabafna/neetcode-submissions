/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* solve(Node* node,unordered_map<Node*,Node*>&m){
        if(node==NULL)
            return NULL;
            
        if(m.find(node)!=m.end()){
           return m[node];
        }
         Node* temp=new Node(node->val);
            m[node]=temp;
            for(auto neighbour:node->neighbors){
                
                Node* cloneNeigh=solve(neighbour,m);
                temp->neighbors.push_back(cloneNeigh);
            }
        
        return temp;
    }
    Node* cloneGraph(Node* node) {
        if (node==NULL){
            return NULL;
        }
        unordered_map<Node*,Node*>m;
        return solve(node,m);

    }
};
