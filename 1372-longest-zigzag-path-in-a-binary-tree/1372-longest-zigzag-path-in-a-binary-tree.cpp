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
    void util(int steps,bool prevLeft, TreeNode* root, int& ans)
    {
        if(!root) return;
        
        ans = max(ans,steps);
        
        if(prevLeft)
        {
            util(steps+1,!prevLeft,root->right,ans); //continuing the sequence as earlier
            util(1, true, root->left, ans); //starting from current and going left
            //NOTE: if previous move is left, we don't need to make a recursive call for starting from current and going right(in zigzag). 
            //Because this is alrready a part of the continuing sequence which will be obviously longer as we go ahead.
        }
        else
        {
            util(steps+1,!prevLeft,root->left,ans); //continuing the sequence as earlier
            util(1, false, root->right, ans); //starting from current and going right
            //NOTE: if previous move is right, we don't need to make a recursive call for starting from current and going left (in zig zag). 
            //Because this is alrready a part of the continuing sequence which will be obviously longer as we go ahead.
        }
    }
    int longestZigZag(TreeNode* root) {
        int ans = INT_MIN;
        util(1,true,root->left,ans); //starting for current and going left
        util(1,false,root->right,ans); //starting from current and going right
        //NOTE: We don't need to make additional calls for excluding current node and going to left and right, because those calls are already covered in the recursive fn.
        return ans==INT_MIN?0:ans;
    }
};