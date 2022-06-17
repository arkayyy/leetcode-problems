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
    //INTUITION: The symmetric BT means left half of BT is mirror image of the right half.
public:
    //Iterative approach:-
    bool util(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 || !root2) return root1==root2;
        if(root1->val!=root2->val) return false;
        return util(root1->left,root2->right)&&util(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
         if(root==NULL) return true;
        // return util(root->left,root->right);
        
        //Deuqe Iterative Approach:-
        deque<TreeNode*> dq;
        dq.push_front(root->left);
        dq.push_back(root->right);
        
        while(!dq.empty())
        {
            TreeNode* left = dq.front();
            TreeNode* right = dq.back();
            dq.pop_front();
            dq.pop_back();
            if(!left && !right) continue;
            if(!left ||!right) return false;
            if(left->val!=right->val) return false;
            
            dq.push_front(left->right);
            dq.push_front(left->left);
            dq.push_back(right->left);
            dq.push_back(right->right);
        }
        
        //Can also be done using 2 queues..the idea is that everytime we have to check the symmetrically opposite node for equality
        
        return true;
    }
};