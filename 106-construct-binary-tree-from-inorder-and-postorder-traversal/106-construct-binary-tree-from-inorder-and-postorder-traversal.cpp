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
    TreeNode* util(int lo, int hi, int& idx, vector<int>&postorder, vector<int>&inorder)
    {
        if( lo>hi) return NULL;
        
        int j = 0;
        while(inorder[j]!=postorder[idx]) ++j;
        
        --idx;
        TreeNode* node = new TreeNode(inorder[j]);
        node->right=util(j+1,hi,idx,postorder,inorder);
        node->left = util(lo,j-1,idx,postorder,inorder);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size()-1;
        return util(0,inorder.size()-1,idx,postorder,inorder);
    }
};