//QUES: - Finding the minimum distance between any 2 nodes in a distance, whose values are given.

#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *left = NULL;
    node *right = NULL;
    int val = 0;

    node(int v)
    {
        val = v;
    }
};

int distNodes(node *root, int v1, int v2, bool v11, bool v22)
{

    if (v11 && v22) //if both v1 and v2 are already found.
        return 0;

    if (root->val == v1) //if current node is v1, then only v2 needs to be found.
    {
        v11 = true;
        if (v22)
            return 0;
        if (v2 < root->val)
            return 1 + distNodes(root->left, v1, v2, v11, v22);
        else
            return 1 + distNodes(root->right, v1, v2, v11, v22);
    }
    if (root->val == v2) //else if current node is v2, then only v1 needs to be found.
    {
        v22 = true;
        if (v11)
            return 0;
        if (v1 < root->val)
            return 1 + distNodes(root->left, v1, v2, v11, v22);
        else
            return 1 + distNodes(root->right, v1, v2, v11, v22);
    }

    if (!v11 && !v22 && (v1 < root->val && v2 > root->val)) // if v1 and v2 lie on opposite sides
        return 2 + distNodes(root->left, v1, v2, v11, true) + distNodes(root->right, v1, v2, true, v22);
    if (!v11 && !v22 && v1 > root->val && v2 < root->val) // if v1 and v2 lie on opposite sides
        return 2 + distNodes(root->left, v1, v2, true, v22) + distNodes(root->right, v1, v2, v11, true);

    if (v11) //if v1 is already found, only v2 needs to be found
    {
        if (v2 < root->val)
            return 1 + distNodes(root->left, v1, v2, v11, v22);
        else
            return 1 + distNodes(root->right, v1, v2, v11, v22);
    }
    if (v22) //if v2 is already found, only v1 needs to be found
    {
        if (v1 < root->val)
            return 1 + distNodes(root->left, v1, v2, v11, v22);
        else
            return 1 + distNodes(root->right, v1, v2, v11, v22);
    }

    if (!v11 && !v22 && v1 < root->val && v2 < root->val) //if both v1 and v2 are not found and lie on left subtree of current node
        return distNodes(root->left, v1, v2, v11, v22);
    //   else if(!v11 && !v22 && v1>root->val && v2>root->val)
    return distNodes(root->right, v1, v2, v11, v22); //if both v1 and v2 are not found and lie on right subtree of current node
}

int main()
{
    node *n1 = new node(10);
    n1->left = new node(5);
    n1->left->right = new node(6);

    // bool v11 = false, v22 = false;
    cout << distNodes(n1, 6, 10, false, false) << endl;
    return 0;
}