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
class Solution
{
public:
    void preorderUtil(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;

        ans.emplace_back(root->val);
        preorderUtil(root->left, ans);
        preorderUtil(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {

        vector<int> ans;

        //recursive relation:-
        //preorderUtil(root,ans);

        //ITERATIVE SOLN.:-
        if (!root)
            return {};

        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty())
        {
            TreeNode *t = s.top();
            s.pop();
            ans.emplace_back(t->val);
            if (t->right) //pushing the right node first and then the left node into the stack because, we want the left node to stay at top of the stack, so that whenever we pop and add to the O/P array, the left node gets added first, followed by right node.
                s.push(t->right);
            if (t->left)
                s.push(t->left);
        }
        return ans;
    }
};