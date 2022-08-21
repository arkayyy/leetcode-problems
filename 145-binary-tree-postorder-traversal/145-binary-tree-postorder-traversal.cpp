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
    void postorderUtil(TreeNode* root, vector<int>&ans)
    {
        if(!root) return;
        
        postorderUtil(root->left,ans);
        postorderUtil(root->right,ans);
        ans.emplace_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        //postorderUtil(root,ans);
        
        //ITERATIVE SOLN. :-
        if(!root) return {};
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty())
        {
            TreeNode* t = s.top();
            s.pop();
            ans.push_back(t->val); 
            if(t->left) s.push(t->left); 
            if(t->right) s.push(t->right);
        }
        reverse(ans.begin(),ans.end()); //reverse or use another stack to reverse the output
        return ans;
        
    }
};