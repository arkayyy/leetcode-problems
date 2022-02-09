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
    void util(vector<int>& curr, TreeNode* root, vector<string> &ans)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
            {
            string res =""; 
            for(auto c: curr)
                {res+=to_string(c); res+="->";}
             res+=to_string(root->val);
             ans.push_back(res);
            //ans.push_back(curr+to_string(root->val)); 
             return; }
        
        curr.push_back(root->val);
        //if(root->left)
            util(curr , root->left,ans);
        //if(root->right)
            util(curr , root->right,ans);
        
        curr.pop_back();
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> ans;
        vector<int> curr;
        util(curr,root,ans);
        return ans;
    }
};