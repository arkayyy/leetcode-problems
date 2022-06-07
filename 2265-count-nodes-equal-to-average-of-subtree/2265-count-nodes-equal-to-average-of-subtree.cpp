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
    int getSumCnt(TreeNode* root, int& cnt)
    {
        if(!root) return 0;
        int sum = root->val;
        ++cnt;
        if(root->left) {sum+=getSumCnt(root->left,cnt);}
        if(root->right) {sum+=getSumCnt(root->right,cnt);}
        return sum;
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        int cnt = 0;
        int sum = getSumCnt(root,cnt);
        
        return ((sum/cnt)==root->val ? 1 : 0)+averageOfSubtree(root->left)+averageOfSubtree(root->right);
    }
};