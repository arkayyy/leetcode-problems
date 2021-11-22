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
    //this helper function follows the principle that the right subtree of the current node be connected to the rightmost 
    //node below its own right node.
    TreeNode* helper(TreeNode* root)
    {
        if(!root->left)
            return root->right;
        if(!root->right)
            return root->left;
        TreeNode* rightChild = root->right;
        TreeNode* rightMost = findLastRight(root->left);
        rightMost->right = rightChild;
        return root->left;
    }
    
    TreeNode* findLastRight(TreeNode* root)
    {
        if(!root->right)
            return root;
        return findLastRight(root->right);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root)
            return NULL;
        if(root->val == key)
            return helper(root);
       
        TreeNode* curr  = root;
        
        while(curr)
        {
            if(key<curr->val)
               {if(curr->left && curr->left->val==key)
                   {curr->left = helper(curr->left); break;}
                else
                    curr  = curr->left;}
            else
            {
                if(curr->right && curr->right->val==key)
                    {curr->right = helper(curr->right); break;}
                else
                    curr = curr->right;
            }
        }
        
        return root;
    }
    
};