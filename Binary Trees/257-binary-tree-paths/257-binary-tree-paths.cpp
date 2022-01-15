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
    void util(string curr, TreeNode* root, vector<string> &ans)
    {
        if(!root->left && !root->right)
            {ans.push_back(curr+to_string(root->val)); return; }
        
        if(root->left)
            util(curr+to_string(root->val)+"->" , root->left,ans);
        if(root->right)
            util(curr+to_string(root->val)+"->" , root->right,ans);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> ans;
        util("",root,ans);
        return ans;
    }
};