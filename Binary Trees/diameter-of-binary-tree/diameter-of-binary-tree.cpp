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
    int findFarthest(TreeNode* root)
    {
        if(!root) return 0;

        return 1+max(findFarthest(root->left),findFarthest(root->right));
    }
  
    void util(TreeNode* root, int& diameter)
    {
        if(!root) return;
        
        int leftd = findFarthest(root->left);
        int rightd = findFarthest(root->right);
        
        diameter = max(diameter, leftd+rightd);
        
        util(root->left, diameter);
        util(root->right,diameter);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int diameter = INT_MIN;
        
        util(root,diameter);
        
        return diameter;
    
    }
};