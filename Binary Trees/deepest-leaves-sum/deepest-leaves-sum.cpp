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
    
    void utilSum(TreeNode* root, int& sum, int level, int& maxlevel)
    {
        if(!root) return;
        
        if(level==maxlevel)
            {sum+=root->val;}
        else if(level>maxlevel) //whenever a greater level is found in the tree, sum is reset to 0 and maxlevel is updated
        {sum = root->val; maxlevel = level;}
        
        utilSum(root->left, sum, level+1, maxlevel);
        utilSum(root->right,sum,level+1, maxlevel);
    }
    
    int deepestLeavesSum(TreeNode* root) {

        //BRUTE FORCE - BFS/Level Order Traversal Approach:-
//         queue<TreeNode*> q;

//         q.push(root);
//         int sumLevel = 0;
//         while(!q.empty())
//         {
//             int len = q.size();
//             sumLevel = 0;
//             for(int i = 0;i<len;i++)
//             {
//                 TreeNode* t = q.front();
//                 sumLevel+=t->val;
//                 q.pop();
//                 if(t->left)
//                     q.push(t->left);
//                 if(t->right)
//                     q.push(t->right);
//             }
//         }
//         return sumLevel;
        
        
        //MOST Optimal Approach - One Pass DFS:-
        int sum = 0, maxlevel = INT_MIN;
        utilSum(root,sum,0,maxlevel);
        
        return sum;
        
        
    }
};