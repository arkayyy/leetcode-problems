//PROBLEM link: https://www.lintcode.com/problem/878/ (LeetCode premium: https://leetcode.com/problems/boundary-of-binary-tree/)

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution
{
public:
    /**
     * @param root: a TreeNode
     * @return: a list of integer
     */
    //prins all left boundary nodes from top to bottom
    void printLeftBoundary(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;

        if (root->left) //in left boundary printing, first priority is given to the left node of every node
        {
            ans.emplace_back(root->val);
            printLeftBoundary(root->left, ans);
        }
        else if (root->right) //if left node doesn't exist
        {
            ans.emplace_back(root->val);
            printLeftBoundary(root->right, ans);
        }
    }
    //prints all right boundary nodes from bottom to top
    void printRightBoundary(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;

        if (root->right) //in right boundary printing, first priority is given to the right node of every node
        {
            printRightBoundary(root->right, ans); //making the functional call first, before adding the node value because we need to print it in
            //an anticlockwise direction,which requires printing the right boundary nodes in a reversed fashion from bottom to top.
            ans.emplace_back(root->val);
        }
        else if (root->left) //if right node doesn't exist
        {
            printRightBoundary(root->left, ans);
            ans.emplace_back(root->val);
        }
    }

    //prints all leave nodes from left to right
    void printLeaves(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;

        printLeaves(root->left, ans); //first we're passing left because, we have to print the leaves from left to right
        if (!root->left && !root->right)
            ans.emplace_back(root->val);
        printLeaves(root->right, ans);
    }

    vector<int> boundaryOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> ans;

        ans.emplace_back(root->val);
        //prins all left boundary nodes from top to bottom
        printLeftBoundary(root->left, ans);
        //prints all leave nodes from left to right
        printLeaves(root->left, ans);
        printLeaves(root->right, ans);
        //prints all right boundary nodes from bottom to top
        printRightBoundary(root->right, ans);

        return ans;
    }
};