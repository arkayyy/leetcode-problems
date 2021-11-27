/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool isPresent(TreeNode *root, TreeNode *node)
    {
        if (!root)
            return false;
        if (root == node)
            return true;

        return isPresent(root->left, node) || isPresent(root->right, node);
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return NULL;

        //if current node is one of the nodes to be found, then search for the other node in the left or right subtree
        if (root == p)
        {
            bool left = isPresent(root->left, q);
            bool right = isPresent(root->right, q);
            if (left || right)
                return root;
        }
        if (root == q)
        {
            bool left = isPresent(root->left, p);
            bool right = isPresent(root->right, p);
            if (left || right)
                return root;
        }

        bool left = isPresent(root->left, p) || isPresent(root->left, q);
        bool right = isPresent(root->right, p) || isPresent(root->right, q);

        //if one node is present in the left subtree, and other in the right, then this is the lowest common ancestor
        if (left && right)
            return root;

        //if both roots are present in the left subtree,move to the left subtree
        if (left)
            return lowestCommonAncestor(root->left, p, q);

        //otherwise move to the right subtree
        return lowestCommonAncestor(root->right, p, q);
    }
};