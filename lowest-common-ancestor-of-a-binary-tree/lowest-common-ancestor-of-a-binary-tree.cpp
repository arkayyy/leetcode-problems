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
    bool isPresent(TreeNode* root, TreeNode* node)
    {
        if(!root) return false;
        
        if(root==node) return true;
        
        return isPresent(root->left,node)||isPresent(root->right,node);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        if(root==p)
        {
            bool left = isPresent(root->left,q);
            bool right = isPresent(root->right,q);
            if(left||right) return root;
        }
        if(root==q)
        {
            bool left = isPresent(root->left,p);
            bool right = isPresent(root->right,p);
            if(left||right) return root;
        }
        
        bool left = isPresent(root->left,p)||isPresent(root->left,q);
        bool right = isPresent(root->right,p)||isPresent(root->right,q);
        
        if(left && right) return root;
        
        if(left) return lowestCommonAncestor(root->left,p,q);
        
        return lowestCommonAncestor(root->right,p,q);
    }
};