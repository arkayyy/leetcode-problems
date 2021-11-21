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
    //
    TreeNode* util(int i1,int i2, int& j, vector<int>& pre, vector<int>&in)
    {
        if(i1>i2)
            return NULL;
        
        int i = 0;
        
        while(in[i]!=pre[j])
            i++;
        j++;
        
        TreeNode* node = new TreeNode(in[i]);
        node->left = util(i1,i-1,j,pre,in);
        node->right = util(i+1,i2,j,pre,in);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int j = 0;
        return util(0,inorder.size()-1,j,preorder,inorder);
    }
};