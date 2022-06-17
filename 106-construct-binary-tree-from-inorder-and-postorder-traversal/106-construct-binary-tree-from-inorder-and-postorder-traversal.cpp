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
        while(inorder[j]!=postorder[idx]) ++j;//finding the current root node position in inorder array
        //left part of the root node in inorder array will be the elements of the left subtree, and on the right will be the elements of the right subtree
        
        --idx; //for moving backwards in the postorder array
        
         //since in postorder, left..right..root sequence is followed, so in backwards, root..right..left sequence must be followed in calling functions
        TreeNode* node = new TreeNode(inorder[j]);
       
        node->right=util(j+1,hi,idx,postorder,inorder);//lo and hi range are passed for right subtree elements in inorder array
        node->left = util(lo,j-1,idx,postorder,inorder);//the lo and hi range are passed for left subtree elements as in inorder array
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size()-1;
        return util(0,inorder.size()-1,idx,postorder,inorder);
    }
};