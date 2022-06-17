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
    void inorder(vector<int>& ans, TreeNode* root)
    {
        if(!root) return;
        inorder(ans,root->left);
        ans.push_back(root->val);
        inorder(ans,root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        // inorder(ans,root);
        // return ans;
        
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(!st.empty() || curr)
        {
            while(curr)
                {st.push(curr); curr = curr->left;}
            curr = st.top(); st.pop();
            ans.emplace_back(curr->val);
            curr = curr->right;
        }
        return ans;
    }
};