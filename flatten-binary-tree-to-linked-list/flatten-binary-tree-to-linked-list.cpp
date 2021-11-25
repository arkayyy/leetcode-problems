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
    TreeNode* util(TreeNode* root)
    {
        if(!root) return NULL;
        
        if(!root->left && !root->right) return root;
        
        // if(!root->left) return util(root->right);
        // if(!root->right) return util(root->left);
        
        TreeNode* storedRight = root->right;
        TreeNode* storedLeft = root->left;
         
        root->right = util(storedLeft);

        root->left = NULL;
         TreeNode* tail = root;
         while(tail->right) tail = tail->right;
        tail->right = util(storedRight);
       
        return root;
    }
    void flatten(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return;
        
        util(root);
        
        
        
    }
};