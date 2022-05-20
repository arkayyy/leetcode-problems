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
    bool isUnivalTree(TreeNode* root) {
        if(!root) true;
        //DFS:-
//         bool left = true, right = true;
//         if(root->left) {if(root->val!=root->left->val) return false;   else left = isUnivalTree(root->left);}
//         if(root->right) {if(root->val!=root->right->val) return false;   else right = isUnivalTree(root->right);}
        
//         return left&&right;
        
        //BFS:-
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* t = q.front(); q.pop();
            if(t->left) {if(t->val!=t->left->val) return false; q.push(t->left);}
            if(t->right) {if(t->val!=t->right->val) return false; q.push(t->right);}
        }
        return true;
    }
};