#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node{
    node* left = NULL;
    node* right = NULL;
    int val = -1;

    node(int _val){
        val = _val;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> levelorder;

    int n;
    cin>>n;

    for(int i = 0;i<n;i++)
    {  vector<int> temp;
        for(int j=0;j<pow(2,i);j++)
        {
            int t;
            cin>>t;
            temp.emplace_back(t);
        }
        levelorder.push_back(temp);
    }

    // for(auto i: levelorder)
    // {
    //     cout<<i<<" ";
    // }

    //node* curr = new node(levelorder[0][0]);

    queue<node*>q;

    node* root = new node(levelorder[0][0]);

    q.push(root);

    cout<<root->val<<endl;

    for(int i = 0;i<n-1;i++)
    {
        int k = 0; // k -> traverse next level
        int len = q.size();

        

        for(int j=0;j< pow(2,i);j++) //j->traverse current level
        {
            node* curr = q.front();
            q.pop();

            if(levelorder[i+1][k]==-1)
                curr->left = NULL;
            else{
                node* left = new node(levelorder[i+1][k]);
                curr->left = left;
                q.push(curr->left);
            }
            k++;
                
            if(levelorder[i+1][k]==-1)
                curr->right = NULL;
            else{
                node* right = new node(levelorder[i+1][k]);
                curr->right = right;
                q.push(curr->right);
            }
            k++;

        }
        
    }

    cout<<"LEVEL ORDER:-"<<endl;

    queue<node*> qe;

    qe.push(root);

    while(!qe.empty())
    {
        
        int len = qe.size();
        

        for(int i = 0;i<len;i++)
        {
            node* c = qe.front();
            qe.pop();

            cout<<c->val<<" ";

            if(c->left)
                qe.push(c->left);

            if(c->right)
                qe.push(c->right);
        }
        cout<<endl;

    }

    // HOGAYAA BOOOO!!!!

    
    return 0;
}
