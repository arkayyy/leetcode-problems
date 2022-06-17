class Solution {
public:
    void preorderUtil(TreeNode* root, vector<int>&ans)
    {
        if(!root) return;
        
        ans.emplace_back(root->val);
        preorderUtil(root->left,ans);
        preorderUtil(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        
        //vector<int> ans;
        
        //recursive relation:-
        //preorderUtil(root,ans);
        
        //ITERATIVE SOLN.:-
//         if(!root) return {};
        
        
//         stack<TreeNode*> s;
//         s.push(root);
        
//         while(!s.empty())
//         {
//             TreeNode* t = s.top();
//             s.pop();
//             ans.emplace_back(t->val);
//              if(t->right) //pushing the right node first and then the left node into the stack because, we want the left node to stay at top of the stack, so that whenever we pop and add to the O/P array, the left node gets added first, followed by right node.
//                 s.push(t->right);
//             if(t->left)
//                 s.push(t->left);
           
//         }
//         return ans;
        
        
        
        //MORRIS Traversal O(N) Time O(1) Space:-
        vector<int> ans;
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

                if(!temp->right) {temp->right = curr; ans.push_back(curr->val); curr = curr->left; } //if no thread found we build the thread and add root value to preorder sequence
                else {temp->right = NULL; curr = curr->right; } //if already thread found to root node(i.e.curr), that means we are visiting this root node 2nd time, after handling its left subtree, 
                //so now will proceed to the right subtree of the root node
            }
        }
        return ans;
    }
};