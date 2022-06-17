class Solution {
public:
    void inorderUtil(TreeNode* root, vector<int> & ans)
    {
        if(!root) return;
        inorderUtil(root->left,ans);
        ans.emplace_back(root->val);
        inorderUtil(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
//         //recursive call:-
//         // inorderUtil(root, ans);
        
//         stack<TreeNode*> s;
//         TreeNode* curr = root;
//         //iterative approach:-
//         while(!s.empty() || curr)
//         {
//             //going tp the left most node and storing all nodes on the way
//             while(curr)
//             {
//                 s.push(curr);
//                 curr = curr->left;
//             }
//             curr = s.top(); //one by one popping the nodes that have come on the way on the left traversal
//             s.pop();
//             ans.emplace_back(curr->val); 
//             curr = curr->right; //if any node has a right subtree, also shifting curr there in order to carry out inorder traversal
//         }
//         return ans;
        
        
        //MORRIS Traversal O(N) Time O(1) Space:-
        TreeNode* curr = root;
        while(curr)
        {
            if(!curr->left)//if no left subtree exists, we have to push the root, and move to right node
            {
                ans.emplace_back(curr->val);
                curr = curr->right;
            }
            else
            {
                //if left subtree exists, our aim will be to create a thread between the last rightmost node of this left subtree with the root, so that we can come back to the root later on
                TreeNode* temp = curr->left;
                while(temp->right && temp->right!=curr) //will stop when there's no right node anymore, or when a thread is found
                    temp = temp->right;
                
                if(!temp->right) {temp->right = curr; curr = curr->left;} //if no thread found we build the thread
                else {temp->right = NULL; ans.emplace_back(curr->val); curr = curr->right; } //if already thread found to root node(i.e.curr), that means we are visiting this root node 2nd time, after handling its left subtree, 
                //so now will add this root node to inorder sequence, and proceed to the right subtree of the root node
            }
        }
        return ans;
    }
};