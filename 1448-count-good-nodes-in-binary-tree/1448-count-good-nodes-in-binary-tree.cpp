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
    int goodNodes(TreeNode* root) {
        int violations = 0, totalNodes = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root, root->val});
        while(!q.empty())
        {
            TreeNode* t = q.front().first; int maxFromRoot = q.front().second; q.pop();
            ++totalNodes;
            if(t->left)
            {
                if(t->left->val<maxFromRoot) ++violations;
                 q.push({t->left, max(t->left->val, maxFromRoot)}); 
            }
            if(t->right)
            {
                if(t->right->val<maxFromRoot) ++violations;
                q.push({t->right, max(t->right->val, maxFromRoot)});
            }
        }
        return totalNodes-violations;
    }
};