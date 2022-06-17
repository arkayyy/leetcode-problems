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
    void flatten(TreeNode* root) {
        while(root)
        {
            if(root->left && root->right)
            {
                //flatenning the left subtree
                TreeNode* t = root->left;
                while(t->right)
                    t = t->right;
                t->right = root->right; //connecting the flatenned left subtree to the right subtree's first node
            }
            if(root->left) //if left subtree exists and has been flattened
                root->right = root->left; //making it the right subtree
            root->left = NULL;//and eliminating the left subtree
            root = root->right;
        }
    }
};