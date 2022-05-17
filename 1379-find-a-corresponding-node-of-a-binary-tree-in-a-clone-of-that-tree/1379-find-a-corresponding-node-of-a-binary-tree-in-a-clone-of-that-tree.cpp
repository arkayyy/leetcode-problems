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
    //INTUITION: Simple BFS Search!
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({original,cloned});
        while(!q.empty())
        {
            TreeNode* orig = q.front().first, *clon = q.front().second;
            q.pop();
            if(orig==target) return clon;
            if(orig->left)
                q.push({orig->left, clon->left});
            if(orig->right)
                q.push({orig->right, clon->right});
        }
        return NULL;
    }
};