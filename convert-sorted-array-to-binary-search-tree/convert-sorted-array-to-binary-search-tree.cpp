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
    TreeNode* createNode(vector<int>nums, int start, int end)
    {
        if(start>end)
            return NULL;
        
        int mid = start + ((end-start)>>1);
        
        TreeNode* node = new TreeNode(nums[mid]);
        
        node->left = createNode(nums,start, mid-1);
        node->right = createNode(nums, mid+1, end);
        
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createNode(nums,0,nums.size()-1);
    }
};