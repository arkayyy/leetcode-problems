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
    void dfs(TreeNode* root, int target,vector<int> curr,vector<vector<int>>& ans)
    {
        if(!root) return;
        
        if(!root->left && !root->right)
        {
            if(target-(root->val)==0)
                {curr.push_back(root->val); ans.push_back(curr);}
            return;
        }

        curr.push_back(root->val);
        
        dfs(root->left,target-root->val, curr,ans);
        dfs(root->right,target-root->val,curr,ans);
    }
    
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        
        vector<vector<int>> ans;
        
        dfs(root,targetSum,{},ans);
        
        return ans;
    }
};