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
class Solution
{
public:
    TreeNode *util(TreeNode *root)
    {
        if (!root)
            return NULL;

        if (!root->left && !root->right)
            return root; //if it's a leaf node no need to proceed any further, connecting this

        TreeNode *storedRight = root->right; //since we are going to be re-connecting the right of every cureent node, we store the previous right in order to recurse.

        root->right = util(root->left); //Since preorder fashion has to be maintained, root->left->right, therefore calling left subtree recursion first

        root->left = NULL; //since in the finalanswer no node must have a left node.
        TreeNode *tail = root;
        while (tail->right)
            tail = tail->right; //finding the tail node of the sequence generated from the left subtree

        tail->right = util(storedRight); //calling recursion for the right subtree of current node

        return root;
    }

    void flatten(TreeNode *root)
    {
        if (!root || (!root->left && !root->right))
            return;

        util(root);
    }
};