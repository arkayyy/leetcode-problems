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
    //INTUITION: Every node in a binary search tree must lie within a range that has been fixed by its ancestor nodes.
    //ALGO: So we take a left range and right range and keep updating it differently as we traverse to the left and right of a node.
    bool util(TreeNode* root, ll leftLim,ll rightLim)
    {
        if(!root) return true;
        
        if((ll)root->val<=leftLim || (ll)root->val>=rightLim) return false;
        
        //for left child node, the value can't be greater or equal to current(ancestor)  node value, so updating only right(upper) limit
        //for right child node, the value can't be less or equal to current(ancestor)  node value, so updating only left(lower) limit
        return util(root->left, leftLim, root->val) && util(root->right, root->val, rightLim);
    }
    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right)
            return true;
        return util(root, LLONG_MIN,LLONG_MAX);
    }
};