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
    //INTUITION: The root of the tree is going to be the minimum value node. 
    //So we have to find the first node in its left and right subtree which is not equal to this root node.
    //the mimimum between these two nodes will be the second min. node.
    //The logic behind this is that all the nodes in the tree have a greater value than all of their children nodes.
    int util(TreeNode* root, int mini)
    {
        if (!root) return -1;
        if (root->val != mini) return root->val; //found the first dissimilar value node
        
        int left = util(root->left, mini), right = util(root->right, mini);
        
        if (left == -1) return right;
        if (right == -1) return left;
        return min(left, right);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        return util(root,root->val);
    }
};