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
    void inorderUtil(TreeNode* root, vector<int> & ans)
    {
        if(!root) return;
        inorderUtil(root->left,ans);
        ans.emplace_back(root->val);
        inorderUtil(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        //recursive call:-
        // inorderUtil(root, ans);
        
        stack<TreeNode*> s;
        TreeNode* curr = root;
        //iterative approach:-
        while(!s.empty() || curr)
        {
            //going tp the left most node and storing all nodes on the way
            while(curr)
            {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top(); //one by one popping the nodes that have come on the way on the left traversal
            s.pop();
            ans.emplace_back(curr->val); 
            curr = curr->right; //if any node has a right subtree, also shifting curr there in order to carry out inorder traversal
        }
        return ans;
    }
};