/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    //INTUITION: BY using a LEVEL ORDER BFS, we can efficiently duplicate all the neighbors of a node. Everytime we duplicate a neighbor, we push that into the queue, so that all of its neighbors are also duplicated in the future.
    Node* cloneGraph(Node* node) {
        
        if(!node) return NULL;
        
        unordered_map<int,Node*> newNodes; //mapped node value -> newly created node duplicate..so if a node has already been duplicated we store it in this map like in a cache
        Node* newHead = new Node(node->val);
        queue< pair<Node*,Node*> > q;
        q.push({node,newHead});
        newNodes[node->val] = newHead;
        while(!q.empty())
        {
            int len = q.size(); //since we are doing level-order
            for(int i = 0; i<len; i++)
            {
                Node* original = q.front().first;
                Node* duplicate =  q.front().second;
                q.pop();
                for(auto a: original->neighbors)
                {
                    if(newNodes.find(a->val)==newNodes.end())
                    {
                        Node* t = new Node(a->val);
                        q.push({a,t});
                        duplicate->neighbors.push_back(t);
                        newNodes[a->val] = t;
                    }
                    else
                        duplicate->neighbors.push_back(newNodes[a->val]);
                }
            }
        }
        
        return newHead;
    }
};