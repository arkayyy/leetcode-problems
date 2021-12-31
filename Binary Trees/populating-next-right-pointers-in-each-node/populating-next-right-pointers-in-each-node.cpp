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

class Solution
{
public:
    Node *connect(Node *root)
    {

        if (!root)
            return root;

        // performing level order traversal and connecting every node of a specific level
        queue<Node *> level;

        level.push(root);
        root->next = NULL;

        while (!level.empty())
        {
            int len = level.size();
            Node *prev = NULL;
            for (int i = 0; i < len; i++)
            {
                Node *temp = level.front();
                level.pop();
                if (prev)
                    prev->next = temp;

                if (temp->left)
                    level.push(temp->left);
                if (temp->right)
                    level.push(temp->right);

                prev = temp;
            }

            prev->next = NULL;
        }

        return root;
    }
};