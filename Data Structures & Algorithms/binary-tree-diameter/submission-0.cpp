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
     int maxDep(TreeNode* root){
        if(root==NULL)
            return 0;
        int left=maxDep(root->left);
        int right=maxDep(root->right);

        return max(left,right)+1;
    }

    int solve(TreeNode* root){
        if(root==NULL)
            return 0;

        int solveleft=solve(root->left);
        int solveright=solve(root->right);

        int left=maxDep(root->left);
        int right=maxDep(root->right);

        int maxi= max(solveleft,solveright);
        return max(left+right,maxi);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        return solve(root);
    }
};
