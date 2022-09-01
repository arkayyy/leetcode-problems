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
    //INTUITION: Let's count the violating nodes or 'not good nodes' using a reverse logic.
    
    //ALGO: The nodes that are not good, it means that in between root and that node, there's an element that is greater than that node's value.
    //So we keep storing the maximum node value occuring between root and a specific node in the queue (extracted as maxFromRoot).
    //If this maximum value > the current node value, then this is a violating node, i.e. NOT A GOOD NODE.
    //We count total number of nodes and subtract number of violating nodes to get the no. of good nodes.
    int goodNodes(TreeNode* root, int maxFromRoot = INT_MIN) {
        int violations = 0, totalNodes = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root, root->val});
        while(!q.empty())
        {
            TreeNode* t = q.front().first; int maxFromRoot = q.front().second; q.pop();
            ++totalNodes;
            if(t->left)
            {
                if(t->left->val<maxFromRoot) ++violations; 
                 q.push({t->left, max(t->left->val, maxFromRoot)}); 
            }
            if(t->right)
            {
                if(t->right->val<maxFromRoot) ++violations;
                q.push({t->right, max(t->right->val, maxFromRoot)});
            }
        }
        return totalNodes-violations;
        
        
        //=======================APPROACH 2: One Liner DFS===========================================//
        // return root?((root->left?goodNodes(root->left, max({root->left->val, maxFromRoot, root->val})):0) + (root->right?goodNodes(root->right, max({root->right->val, maxFromRoot, root->val})):0) + (root->val>=maxFromRoot) ):0;
    }
};