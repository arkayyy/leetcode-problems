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


//q -> []


class Solution {
public:
    
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return false;
        queue<TreeNode*> q;
        
        
        q.push(root);
        
        int level = 0;
        
        while(!q.empty())
        {
            
            int len = q.size();
            
            int prev = -1;
            
            for(int i = 0;i<len;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                if((level&1) == 1) //odd level
                {
                    if(((t->val)&1)==1)
                        return false;
                    if(prev==-1)
                        prev = t->val;
                    else if(t->val >= prev)
                        return false;
                }
                else //even level
                {
                    if(((t->val)&1)==0)
                        return false;
                    if(prev==-1)
                        prev = t->val;
                    else if(t->val <= prev)
                        return false;
                }
                
                prev = t->val;
                
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
        level++;
        }
        
        
        return true;
    }
};