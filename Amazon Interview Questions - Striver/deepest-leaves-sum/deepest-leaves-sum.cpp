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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        
        q.push(root);
        int sumLevel = 0;
        while(!q.empty())
        {
            int len = q.size();
            sumLevel = 0;
            for(int i = 0;i<len;i++)
            {
                TreeNode* t = q.front();
                sumLevel+=t->val;
                q.pop();
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
        }
        return sumLevel;
    }
};