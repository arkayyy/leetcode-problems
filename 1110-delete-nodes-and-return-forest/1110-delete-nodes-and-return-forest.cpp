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
    TreeNode* util(TreeNode* root, vector<TreeNode*>& ans, set<int>& deleted, bool isRoot)
    {
        if(!root) return NULL;
        bool toDelete = deleted.find(root->val)!=deleted.end();
        if(isRoot && !toDelete) ans.push_back(root);
        root->left = util(root->left, ans, deleted, toDelete);
        root->right = util(root->right, ans, deleted, toDelete);
        return toDelete?NULL:root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> deleted;
        vector<TreeNode*> ans;
        for(auto node: to_delete) deleted.insert(node);
        util(root,ans,deleted,true);
        return ans;
    }
};