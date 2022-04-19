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
    //INTUITION: We are doing inorder traversal, at any point if we find the current node value conflicts its ancestor node value as per rules of a BST, we store both nodes.
    
    //ALGO: For every node, we check violation caused by any of its child/grandchild/further lower level nodes in its right subtree(we can also check in left subtree)...
    void check(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& end) {
        if (!root) return;
        check(root->left, prev, first, end); //traversing to the leftmost node first, then we will backtrack and check in all traversed nodes' right subtrees
        if (prev) {
            if (root->val < prev->val) { //conflict found (if any node in the right subtree has value less than its ancestor node)
                if (!first) { //first if already there, means it is the most ancestor node already which needs to be swapped, so no need to change
                    first = prev;
                }
                end = root;//we change end everytime the violation occurs because we need to find the lowermost violating node
            }
        }
        prev = root; //setting current root as prev
        check(root->right, prev, first, end);//and then checking for conflicts in all nodes of the right subtree
    }
    void recoverTree(TreeNode* root) {
        TreeNode *prev = NULL, *first = NULL, *end = NULL;
        check(root, prev, first, end);
        swap(first->val, end->val);
        return;
    }
};