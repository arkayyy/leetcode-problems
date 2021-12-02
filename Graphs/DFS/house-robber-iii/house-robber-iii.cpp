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
    int robber(TreeNode *root, int &lm, int &rm)
    {
        if (!root)
            return 0;

        int lm1 = 0; // for storing max sum if continued from root->left->left
        int rm1 = 0; // for storing max sum if continued from root->left->right
        int lm2 = 0; // for storing max sum if continued from root->right->left
        int rm2 = 0; // for storing max sum if continued from root->left->left

        lm = robber(root->left, lm1, rm1);  // lm denotes the maximum amount robbed if continued from current node's left child onwards
        rm = robber(root->right, lm2, rm2); // rm denotes the maximum amount robbed if continued from current node's right child onwards

        // the amount robbed can be max of either including the root and continuing from its grandchildren nodes, or continuing from its immediate left and right child excluding root itself.
        return max(root->val + lm1 + rm1 + lm2 + rm2, lm + rm);
    }
    int rob(TreeNode *root)
    {
        int lm = 0, rm = 0;
        return robber(root, lm, rm);
    }
};