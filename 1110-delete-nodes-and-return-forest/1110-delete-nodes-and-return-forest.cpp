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
        if(isRoot && !toDelete) ans.push_back(root); //if the current node is a root node and it is not supposed to be deleted, it will stay in our final answer tree
        root->left = util(root->left, ans, deleted, toDelete); //toDelete is passed as isRoot for the child node of current node, because if current node is to be deleted, the child node will be the new root node
        root->right = util(root->right, ans, deleted, toDelete);
        return toDelete?NULL:root; //if current node is to be deleted, we return NULL in place of it
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> deleted;
        vector<TreeNode*> ans;
        for(auto node: to_delete) deleted.insert(node);
        util(root,ans,deleted,true);
        return ans;
    }
};