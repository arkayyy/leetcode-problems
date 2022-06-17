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
    TreeNode* util(int lo, int hi, int& idx, vector<int>&preorder, vector<int>&inorder)
    {
        if(lo>hi) return NULL;
        int j = 0;
        while(inorder[j]!=preorder[idx]) ++j; //finding the current root node position in inorder array
        //left part of the root node in inorder array will be the elements of the left subtree, and on the right will be the elements of the right subtree
        
        ++idx; //increment the index for accessing element from preorder array
        
        //since root..left..right sequence is followed in followed in preorder array, so calling functions in same sequence
        TreeNode* node = new TreeNode(inorder[j]);
        
        node->left = util(lo,j-1,idx,preorder,inorder); //the lo and hi range are passed for left subtree elements as in inorder array
        node->right = util(j+1,hi,idx,preorder,inorder);//lo and hi range are passed for right subtree elements in inorder array
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return util(0,inorder.size()-1,idx,preorder,inorder);
    }
};