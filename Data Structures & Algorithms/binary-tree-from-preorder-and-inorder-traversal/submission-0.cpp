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

    int preIdx=0;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int st,int end,unordered_map<int,int>&m){
        if(st>end)
            return NULL;
        int ele=preorder[preIdx++];
        int position=m[ele];
        TreeNode* head=new TreeNode(ele);
        TreeNode* left=head->left=solve(preorder,inorder,st,position-1,m);
        TreeNode* right=head->right=solve(preorder,inorder,position+1,end,m);
        return head;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        return solve(preorder,inorder,0,n-1,m);
    }
};
