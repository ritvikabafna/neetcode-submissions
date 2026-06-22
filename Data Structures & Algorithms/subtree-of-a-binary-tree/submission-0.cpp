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
    bool check(TreeNode* p,TreeNode* q){
         if(q==NULL && p==NULL)
            return true;
        
        if((p!=NULL && q==NULL) ||(p==NULL  && q!=NULL))
            return false;
        
        bool left=check(p->left,q->left);
        bool right=check(p->right,q->right);

        return ((left && right) && p->val==q->val);
    }
    bool solve(TreeNode* root, TreeNode* subRoot){
        if(root==NULL)
            return false;
        if(root->val==subRoot->val){
            bool ans=check(root,subRoot);
            if(ans)
                return ans;
        }
        bool left= solve(root->left,subRoot);
        bool right=solve(root->right,subRoot);
        return left||right;

        }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL)
            return true;
        bool isSubTr=false;
        return solve(root,subRoot);

    }
};
