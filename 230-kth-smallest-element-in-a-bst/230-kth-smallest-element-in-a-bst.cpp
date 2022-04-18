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
    int kthSmallest(TreeNode* root, int &k) {
        if(!root) return 0; //doesn't matter what we return here, writing just for handling termination of recursive fn
        int x = kthSmallest(root->left, k); //traverses and reaches the leftmost(smallest) node first
        //when k==0, we return the kth smallest node that we already have stored in x as our answer
        //when (--k) or k-1==0, it means there are k-1 nodes to the left of current node and this is the desired answer (kth smallest)
        //otherwise, we traverse to the right to find greater value node until we reach kth smallest node
        return k==0?x:((--k)==0? root->val : kthSmallest(root->right, k));
    }
};