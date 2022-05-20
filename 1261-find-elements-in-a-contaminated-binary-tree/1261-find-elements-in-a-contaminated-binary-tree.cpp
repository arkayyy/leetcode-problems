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
class FindElements {
    private: 
    TreeNode* head;
    void recovery(TreeNode* root)
    {
        if(!root) return;
        if(root->left) {root->left->val = 2*root->val + 1; recovery(root->left);}
        if(root->right) {root->right->val = 2*root->val + 2; recovery(root->right);}
    }
    bool search(TreeNode* root, int val)
    {
        if(!root) return false;
        if(root->val==val) return true;
        return search(root->left, val)||search(root->right,val);
    }
public:
    FindElements(TreeNode* root) {
        head = root;
        root->val = 0;
        recovery(root);
    }
    
    bool find(int target) {
        return search(head,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */