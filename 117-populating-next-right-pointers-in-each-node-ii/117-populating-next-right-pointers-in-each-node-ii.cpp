/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        queue<Node*> q; 
        q.push(root);
        int l=0;
        while(!q.empty())
        {
            Node* curr = new Node(5);
            int len = q.size();
            for(int i=0;i<len;i++)
            {
                curr->next = q.front();
                curr=curr->next;
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            if(curr)
            curr->next = NULL;
        }
        return root;
    }
};