/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        queue<pair<Node*,int>> q;
        q.push({root,1});
        int ans = 1;
        while(!q.empty())
        {
            Node* t = q.front().first; int level = q.front().second; q.pop();
            for(auto c: t->children)
                {ans = max(ans,level+1); q.push({c,level+1});}
        }
        return ans;
    }
};