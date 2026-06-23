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

class Solution {
public:
    int cnt=0;
    void solve(TreeNode* root,int maxi){
        if(root==NULL)
            return ;
        if(max(maxi,root->val)<=root->val){
            cnt++;
            maxi=max(maxi,root->val);
        }
        solve(root->left,maxi);
        solve(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        if (root==NULL)
            return 0;
        
        solve(root,INT_MIN);
        return cnt;
    }
};
