/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.

    void solve(TreeNode* root,string& ans){
        if(root==NULL){
            ans+="N,";
            return;
        }
        
        ans+=to_string(root->val);
        ans+=",";
        solve(root->left,ans);
        solve(root->right,ans);
    }
    string serialize(TreeNode* root) {
        string ans="";
        solve(root,ans);
        return ans;
    }
    TreeNode* sol(string data,int& idx,int n){
        if(idx>=n)
            return NULL;
        string num;
            while(idx < n && data[idx] != ',') {
            num += data[idx];
            idx++;
            }
        
        idx++;
        if(num=="N")
            return NULL;
        TreeNode* root = new TreeNode(stoi(num));

        root->left = sol(data, idx,n);
        root->right = sol(data, idx,n);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n=data.size();
        int idx=0;
        return sol(data,idx,n);
    }
};
