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
    int findMax(TreeNode* root) //finds maximum value appearing in any subtree of root
    {
        if(!root)
            return INT_MIN;
        
        return max(root->val , max(findMax(root->left),findMax(root->right)));
    }
    int findMin(TreeNode* root) //finds minimum value appearing in any subtree of root
    {
        if(!root)
            return INT_MAX;
        
        return min(root->val, min(findMin(root->left),findMin(root->right)));
    }
    int minDiffInBST(TreeNode* root) {
        if(!root)
            return INT_MAX;
        
        int mini = INT_MAX;
        
        int maxl = findMax(root->left); //finding the maximum element in the left subtree
        int minr = findMin(root->right);///finding the minimum element in the right subtree
        //above steps are because the max element of the left subtree in a BST, will be just smaller than the root's value. and the min element of the right subtree will be just greater than the root. So the min. difference of the root's value can only be with these two.
        
        if(maxl!=INT_MIN)
            mini = min(mini, abs(root->val - maxl));
        if(minr!=INT_MAX)
            mini = min(mini,abs(root->val - minr)); 
        
        return min(mini,min(minDiffInBST(root->left),minDiffInBST(root->right)));
    }
};