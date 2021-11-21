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
    TreeNode* util(int i1, int i2, int& j, vector<int>& in, vector<int>&post)
    {
        if(i1>i2)         //base case if no more elements in the range
            return NULL;
        
        int i = 0;
        
        while(in[i]!=post[j])
            i++; //finding the current postorder element in the inorder element
        
        j--; //decreasing the pointer of the postorder array (as we are traversing the postorder array from behind, and this j is a global pointer and will stop only at an index which is supposed to be a root)
        
        TreeNode* node = new TreeNode(in[i]); //creating the new node
        node->right = util(i+1,i2, j, in, post); //passing the right range of the inorder array from i+1 to i2, to create the right subtree. It returns the root of the right subtree
        node->left = util(i1,i-1,j,in,post);//passing the left range of the inorder array from i1 to i-1, to create the left subtree. It returns the root of the leftt subtree
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int j = postorder.size()-1;//since we start traversing from the end of the postorder array(where the root node value is located)
        return util(0,inorder.size()-1, j, inorder, postorder);
        
    }
};
