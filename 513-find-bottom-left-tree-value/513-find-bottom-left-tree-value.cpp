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
    void util(TreeNode* root, int depth, int& maxDepth, int& ans)
    {
        if(!root) return;
        if(depth>maxDepth)
        {
            maxDepth  = depth;
            if(!root->left && !root->right)
                ans = root->val;
        }
        
        util(root->left,depth+1,maxDepth,ans);
        util(root->right,depth+1,maxDepth,ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        
        int ans = -1, maxDepth = -1;
        util(root,0,maxDepth,ans);
        return ans;
    }
};