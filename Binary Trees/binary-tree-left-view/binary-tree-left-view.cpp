/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
void util(Node* root, vector<int>&ans, int level, int&maxLevel)
{
    if(!root) return;
    
    if(level>maxLevel)
    {maxLevel = level; ans.push_back(root->data);}

    util(root->left,ans,level+1,maxLevel);

    util(root->right,ans,level+1,maxLevel);
}
vector<int> leftView(Node *root)
{
    if(!root)
        return {};
   
   vector<int>ans;
   int maxLevel = INT_MIN;
   util(root,ans,0,maxLevel);
   return ans;
}