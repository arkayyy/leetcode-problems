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
    //INTUITION: Kind of like matrix chain multiplication concept (and similar to no. of structurally unique BSTs). 
    //For every node left subtree will contain some nodes and right will contain some. We check for all combinations of no. of nodes in left & right subtree.
    
    unordered_map<int,vector<TreeNode*>> cache; //to store the heads for all trees with a specific number of nodes
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n==1) return {new TreeNode(0)};

        if(cache.find(n)!=cache.end()) return cache[n];
        vector<TreeNode*> res;
        for(int i = 1; i<n;i+=2) // i+=2 to avoid repitition/swapping of i's value and n-i-1; to avoid repititive calls
        {
            int noOfNodesLeftSubtree = i, noOfNodesRightSubtree = n-i-1;
            for(auto l: allPossibleFBT(noOfNodesLeftSubtree))
            {
                for(auto r: allPossibleFBT(noOfNodesRightSubtree))
                {
                    TreeNode* temp = new TreeNode(0);
                    temp->left = l;
                    temp->right = r;
                    res.push_back(temp);
                }
            }
        }
        cache[n] = res;
        return res;
    }
};