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
    int total = 0;
    void util(TreeNode* root, int sum)
    {
        if(!root)
            { return;}
        if(!root->left && !root->right)
        {total+=(sum*10+root->val); return;}
       
        
        util(root->left, sum*10 + root->val);
        util(root->right,sum*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        util(root,0);
        return total;
    }
};