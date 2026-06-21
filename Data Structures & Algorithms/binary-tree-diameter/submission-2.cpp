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
int ans=0;
     int maxDep(TreeNode* root){
        if(root==NULL)
            return 0;
        int left=maxDep(root->left);
        int right=maxDep(root->right);

        ans=max(ans,left+right);
        return max(left,right)+1;
    }

    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int sol=maxDep(root);
        return ans;
    }
};
