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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (!root)
            return 0;

        // SOLN-1: moving in inorder fashion
        // return rangeSumBST(root->left,low,min(root->val,high))+((root->val >= low && root->val<=high)?root->val:0)+rangeSumBST(root->right, max(root->val,low),high);

        // SOLN-2:
        if (root->val >= low && root->val <= high)
            return root->val + rangeSumBST(root->left, low, min(root->val, high)) + rangeSumBST(root->right, max(root->val, low), high);

        if (root->val < low) // because in left subtree of root, only values even lesser than root will be obtained
            return rangeSumBST(root->right, max(root->val, low), high);

        // if(root->val > high) //because in the right subtree, only values even greater than root will be obtained
        return rangeSumBST(root->left, low, min(root->val, high));
    }
};