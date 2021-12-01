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
    
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0;
        
        //Doing a modified level order traversal, wherein we are also indexing the nodes as they are included in the current level.
        //As we traverse through the current level, we insert the left of the current node (residing in the below level) into the queue with index 2*i and the right of the current node with index 2*i+1. 
        //This is because for every node in the current level there will be at max 2 nodes connected to it in the next level. 
        queue<pair<TreeNode*,int>> q;
        
        q.push({root,0});
        
        int ans = INT_MIN;
        
        while(!q.empty())
        {
            int len = q.size();
            int mmin = q.front().second;
            int first, last;
            for(int i = 0;i<len;i++){ //traversing through the current level
                
            int idx = q.front().second - mmin;
            TreeNode* t = q.front().first;
            q.pop();
                
            if(i==0) first = idx;
            if(i==len-1) last = idx;
            
            if(t->left)
                q.push({t->left, 2*idx + 1}); // we are doing 2* i since even if there is not a left or right branch of the current node present in the next level, their indexes are counted too.
            if(t->right)
                q.push({t->right, 2*idx + 2});
            }
            
            ans=max(ans,last-first+1);
            
        }
        
        return ans;
        
    }
};