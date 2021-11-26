// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
public:
    //Function to return a list of nodes visible from the top view
    //from left to right in Binary Tree.
    void util(Node *root, int width, int level, map<int, vector<int>> &mp)
    {
        if (!root)
            return;

        if (mp.find(width) == mp.end())
        {
            mp[width] = {root->data, level};
        } //if that horizontal height isn't already mapped a node in the map, we map it for the first time.

        else if (level <= mp[width][1]) //if that horizontal height i already mapped, we check if current level is less that the level that is already present of the element in the map mapped to this width
            mp[width] = {root->data, level};

        util(root->left, width - 1, level + 1, mp);
        util(root->right, width + 1, level + 1, mp);
    }
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        map<int, vector<int>> mp;

        util(root, 0, 0, mp);

        for (auto i : mp)
        {
            ans.push_back(i.second[0]);
        }

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    cin.ignore(256, '\n');
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends