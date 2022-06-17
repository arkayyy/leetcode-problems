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
    bool search(TreeNode* root)
    {
        if(!root) return false;
        if(root->val == 1) return true;
        
        return search(root->left)||search(root->right);
    }
    TreeNode* pruneTree(TreeNode* root)
    {
        if(!root) return NULL;
        bool left = search(root->left);
        bool right = search(root->right);
        
        if(!left) root->left = NULL;
        if(!right) root->right = NULL;
        pruneTree(root->left);
        pruneTree(root->right);
        return !left&&!right&&root->val==0?NULL:root;
    }
};