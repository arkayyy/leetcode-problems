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
    void preorderUtil(TreeNode* root, vector<int>&ans)
    {
        if(!root) return;
        
        ans.emplace_back(root->val);
        preorderUtil(root->left,ans);
        preorderUtil(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        //preorderUtil(root,ans);
        if(!root) return {};
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty())
        {
            TreeNode* t = s.top();
            s.pop();
            ans.emplace_back(t->val);
             if(t->right)
                s.push(t->right);
            if(t->left)
                s.push(t->left);
           
        }
        return ans;
    }
};