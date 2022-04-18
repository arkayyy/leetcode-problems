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
    //INTUITION: We are making all possible leaf-to-root strings and storing the minimum in ans
    void util(TreeNode *root, string curr, string& ans){
        if(root->left==NULL && root->right==NULL){
            curr.push_back(root->val+'a');
            reverse(curr.begin(),curr.end());  //reversing the string in the end to make it leaf-to-root, from root-to-leaf
            ans=min(ans,curr);
        }

        if(root->left){
            curr.push_back(root->val+'a'); 
            util(root->left,curr,ans);
            curr.pop_back();
        }
        if(root->right){
            curr.push_back(root->val+'a');
            util(root->right,curr,ans);
            curr.pop_back();
        }
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "~"; //can take any character with ASCII value greater than that of z
        util(root,"", ans);
        return ans;
    }
};