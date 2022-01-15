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
    //EXPLANATION: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/discuss/143775/very-easy-to-understand-c%2B%2B-solution.
    
    //ALGO: We use an intuition that there are 3 directions in which the k-distant nodes can be found, towards the parent/ancestor, towards left subtree and towards right subtree.
    //So we are first mapping the parent for each node in the tree and then from target node, we are traversing in all 3 directions using DFS.
    void findParent(unordered_map<TreeNode*,TreeNode*> & parent, TreeNode* root)
    {
        if(!root) return;
        if(root->left){
            parent[root->left] = root;
            findParent(parent,root->left);
        }
        if(root->right){
            parent[root->right] = root;
            findParent(parent, root->right);
        }
    }
    void dfs(TreeNode* root, int k, unordered_map<TreeNode*,TreeNode*>& parent, unordered_set<TreeNode*>&visited, vector<int>& ans)
    {
        if(visited.find(root)!=visited.end()) return;
        
        visited.insert(root);
        
        if(k==0) {ans.push_back(root->val); return;}
        
        //traversing towards left subtree
        if(root->left)
            dfs(root->left,k-1,parent,visited,ans);
        //traversing towards right subtree
        if(root->right)
            dfs(root->right,k-1,parent,visited,ans);
        //traversing towards the parent
        TreeNode* p = parent[root];
        if(p)
            dfs(p,k-1,parent,visited,ans);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_set<TreeNode*> visited;
        
        vector<int> ans;
        
        findParent(parent,root);
        dfs(target,k,parent,visited,ans);//doing DFS from target node in all 3 directions
        
        return ans;
    }
};