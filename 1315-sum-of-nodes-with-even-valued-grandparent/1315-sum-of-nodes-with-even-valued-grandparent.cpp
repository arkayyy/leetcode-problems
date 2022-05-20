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
    //INTUITION: Simple BFS!
    int sumEvenGrandparent(TreeNode* root) {
        queue<TreeNode*> q;
        int ans = 0;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* t = q.front(); q.pop();
            if(t->left){
                //Checking both grandchilds in left subtree:-
                if(t->left->left && (t->val&1)==0) ans+=t->left->left->val; 
                if(t->left->right && (t->val&1)==0) ans+=t->left->right->val; 
                q.push(t->left); 
            }
            if(t->right) {
                //Checking both grandchilds in right subtree:-
                if(t->right->left && (t->val&1)==0) ans+=t->right->left->val; 
                if(t->right->right && (t->val&1)==0) ans+=t->right->right->val; 
                q.push(t->right); 
            }
        }
        return ans;
    }
};