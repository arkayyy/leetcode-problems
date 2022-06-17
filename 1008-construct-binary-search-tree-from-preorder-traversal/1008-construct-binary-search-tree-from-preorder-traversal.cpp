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
    TreeNode* util(int& idx, vector<int>&preorder, int bound)
    {
        if(idx==preorder.size() || preorder[idx]>bound) return NULL;
        
        TreeNode* node = new TreeNode(preorder[idx++]);
        node->left = util(idx,preorder,node->val);
        node->right = util(idx,preorder,bound);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return util(idx,preorder,INT_MAX);
    }
};