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
    map<int,multiset<pair<int,int>>> mp;
    void util(TreeNode* root, int level, int width)
    {
        if(!root) return;
        mp[width].insert({level,root->val});
        util(root->left,level+1,width-1);
        util(root->right,level+1,width+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        util(root,0,0);
        vector<vector<int>> ans;
        for(auto m: mp)
        {
            vector<int> curr;
            for(auto e: m.second) curr.emplace_back(e.second);
            ans.push_back(curr);
        }
        return ans;
    }
};