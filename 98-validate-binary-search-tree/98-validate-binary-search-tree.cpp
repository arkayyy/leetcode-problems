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
#define ll long long
class Solution {
public:
    bool util(TreeNode* root, ll leftLim,ll rightLim)
    {
        if(!root) return true;
        
        if((ll)root->val<=leftLim || (ll)root->val>=rightLim) return false;
        
        return util(root->left, leftLim, root->val) && util(root->right, root->val, rightLim);
    }
    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right)
            return true;
        return util(root, LLONG_MIN,LLONG_MAX);
    }
};