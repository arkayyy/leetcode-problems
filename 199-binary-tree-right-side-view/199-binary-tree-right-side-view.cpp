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
    void dfs(TreeNode* root,int level, vector<int>& ans)
    {
        //IDEA for DFS: the right boundary would consist of the rightmost node and their right child of every level. Except when the right child is NULL, we go to left child, and again try to extract the rightmost nodes at every level below that.
        if(!root) return;  
        
        if(ans.size()==level) ans.emplace_back(root->val); //IMP step: since level initially starts from 0 (0 indexed), so just when the level reaches the value ans.size(), it means current recursive call candidate holds the value for rightmost node of this new level
        
        //if(!root->left && !root->right) {ans.emplace_back(root->val); return;}
        dfs(root->right, level+1, ans);
        
        dfs(root->left, level+1, ans);  
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        //BFS Level Order:-
        // vector<int> ans;
        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty())
        // {
        //     int len = q.size();
        //     TreeNode* t;
        //     for(int i = 0; i<len; i++)
        //     {
        //         t = q.front(); q.pop();
        //         if(t->left) q.push(t->left);
        //         if(t->right) q.push(t->right);
        //     }
        //     ans.emplace_back(t->val); //at every level, 't' will finally contain last node of that level
        // }
        // return ans;
        
        //Recursive DFS:-
        vector<int> ans;
        dfs(root,0,ans);
        return ans;
    }
};