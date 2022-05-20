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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,int> isRoot;//we will take convention => 2: for potential candidate for root node, 1: for any child node. 
        //LOGIC: Any child node can't be the root node ever.
        unordered_map<int,TreeNode*> mp; //storing pointers created for every node
        for(auto d: descriptions)
        {
            if(mp.find(d[0])==mp.end()) {mp[d[0]] = new TreeNode(d[0]);}
            
            if(mp.find(d[1])==mp.end()) {mp[d[1]] = new TreeNode(d[1]);}
            
            if(d[2])
                mp[d[0]]->left = mp[d[1]];
            if(!d[2])
                mp[d[0]]->right = mp[d[1]];
               
            if(isRoot.find(d[0])==isRoot.end()) isRoot[d[0]] = 2; //marked as potential candidate for root node only if previously never marked as child
            isRoot[d[1]] = 1; //marked as child
        }
               
        for(auto node: isRoot)
            if(node.second==2) //found root node (only node which is not a child node)
               return mp[node.first];
               
        return NULL;
    }
};