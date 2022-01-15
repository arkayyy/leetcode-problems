/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        if(root->val==p->val || root->val==q->val) return root; //if current node is one of the nodes to be found, we can't traverse ahead as we will lose this node then. So we return current node as LCA

        if((p->val > root->val && q->val < root->val) || (p->val < root->val && q->val > root->val)) //if one node lies in left subtree and other in right, we can't traverse ahead, current node is the LCA
            return root;
        
        if(p->val > root->val && q->val>root->val) //if both nodes to be found lie in right subtree
            return lowestCommonAncestor(root->right,p,q);
        if(p->val < root->val && q->val < root->val) //if both nodes to be found lie in left subtree
            return lowestCommonAncestor(root->left,p,q);
        
        return NULL; //this line won't ever be executed
    }
};