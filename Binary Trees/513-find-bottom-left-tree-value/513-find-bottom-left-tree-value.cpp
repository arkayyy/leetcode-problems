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
        if(depth>maxDepth) //for every new level...
        {
            maxDepth  = depth;
            if(!root->left && !root->right) //we store only the first leaf node encountered at that level...
                ans = root->val;
            //This will give us the desired answer because below, we are first making recursive call towards root->left and then towards root->right, so at every new level the leftmost node will  be encountered first
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