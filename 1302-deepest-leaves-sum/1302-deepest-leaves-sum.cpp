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
    void util(int& sum, int currLevel, int& maxLevel, TreeNode* root)
    {
        if(!root) return;
        if(currLevel>maxLevel) {maxLevel = currLevel;sum=0; }
        
        if(currLevel==maxLevel) sum+=root->val;
        
        util(sum, currLevel+1, maxLevel, root->left);
        util(sum, currLevel+1, maxLevel, root->right);
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0, maxLevel = 0;
        util(sum,0,maxLevel,root);
        return sum;
    }
};