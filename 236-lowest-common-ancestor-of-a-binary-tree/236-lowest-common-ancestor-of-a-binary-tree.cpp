/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool find(int val, TreeNode* root)
    {
        if(!root) return false;
        if(root->val==val) return true;
        
        return find(val,root->left)|| find(val,root->right);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        if(root->val==p->val || root->val==q->val) return root;
        
        if(find(p->val,root->left) && find(q->val,root->left)) return lowestCommonAncestor(root->left,p,q);
        
        if(find(p->val,root->right) && find(q->val,root->right)) return lowestCommonAncestor(root->right,p,q);
        
        return root;
    }
};