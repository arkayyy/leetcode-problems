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
    //VERY SIMILAR to construct-binary-tree-from-inorder-and-postorder-traversals. The slight difference
    //is that for postorder array, we have to take a pointer that traverses from the end
    //of the postorder array to the start. Because the root exists at the end of postorder 
    //array. But in preorder array, we take a pointer that traverses from the starting
    //of the preorder array since the root exists at the start of the preorder array.
    TreeNode* util(int i1,int i2, int& j, vector<int>& pre, vector<int>&in)
    {
        if(i1>i2)  //base case if no more elements in the range
            return NULL;
        
        int i = 0;
        
        while(in[i]!=pre[j])
            i++;  //finding the current postorder element in the inorder element
       
        j++; //increasing the pointer of the preorder array (as we are traversing the preorder array from starting to end, and this j is a global pointer and will stop only at an index which is supposed to be a root)
        
        TreeNode* node = new TreeNode(in[i]);
        node->left = util(i1,i-1,j,pre,in);//passing the left range of the inorder array from i1 to i-1, to create the left subtree. It returns the root of the leftt subtree
        node->right = util(i+1,i2,j,pre,in);  //passing the right range of the inorder array from i+1 to i2, to create the right subtree. It returns the root of the right subtree
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int j = 0; //sunce we start traversing from beginning(where root node value is located) of the preorder array
        return util(0,inorder.size()-1,j,preorder,inorder);
    }
};