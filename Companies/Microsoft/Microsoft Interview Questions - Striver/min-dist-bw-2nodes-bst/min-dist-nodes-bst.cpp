#include<bits/stdc++.h>
using namespace std;

struct node
{
    node* left = NULL;
    node* right = NULL;
    int val = 0;

    node(int v)
    {
        val = v;
    }
};

int distNodes(node* root, int v1, int v2, bool v11, bool v22)
{

    if(v11 && v22)
        return 0;
    
    if(root->val == v1)
    {   v11 = true;
        if(v22)
            return 0;
        if(v2<root->val)
            return 1+distNodes(root->left, v1, v2, v11, v22);
        else
            return 1+distNodes(root->right, v1, v2, v11, v22);
    }
    if(root->val == v2)
    {
        v22 = true;
        if(v11)
            return 0;
        if(v1<root->val)
            return 1+distNodes(root->left, v1, v2, v11, v22);
        else
            return 1+distNodes(root->right, v1, v2, v11, v22);
    }
    if(!v11 && !v22 && (v1<root->val && v2>root->val))
        return 2+distNodes(root->left, v1,v2,v11,true)+distNodes(root->right, v1,v2,true,v22);
    if(!v11 && !v22 && v1>root->val && v2<root->val)
        return 2+distNodes(root->left, v1,v2,true,v22)+distNodes(root->right, v1,v2,v11,true);
    
    

    if(v11)
    {
        if(v2<root->val)
            return 1+distNodes(root->left,v1,v2,v11,v22);
        else 
            return 1+distNodes(root->right,v1,v2,v11,v22);
    }
    if(v22)
    {
        if(v1<root->val)
            return 1+distNodes(root->left,v1,v2,v11,v22);
        else 
            return 1+distNodes(root->right,v1,v2,v11,v22);
    }

    if(!v11 && !v22 && v1<root->val && v2<root->val)
        return distNodes(root->left,v1,v2,v11,v22);
 //   else if(!v11 && !v22 && v1>root->val && v2>root->val)
    return distNodes(root->right,v1,v2,v11,v22);
}


int main()
{
    node* n1 = new node(10);
    n1->left = new node(5);
    n1->left->right=new node(6);
    
    // bool v11 = false, v22 = false;
    cout<< distNodes(n1,6,10,false,false) <<endl;
    return 0;
}