class Solution {
public:
    //INTUITION: The minimum height tree would be produced by BFS traversing (one step at a time) from the leaf nodes inwards, until the indegree of all the nodes are extinguished.
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0) return {};
        if(n==1) return {0};
        
        unordered_map<int,vector<int>> adj;
        vector<int> ans;
        vector<int> indegree(n,0);
        for(auto& e:edges)
            adj[e[0]].emplace_back(e[1]), adj[e[1]].emplace_back(e[0]),++indegree[e[0]],++indegree[e[1]];
        
        queue<int> q;
        for(int i = 0; i<n; ++i) if(indegree[i]==1) q.push(i);
        while(!q.empty())
        {
            ans.clear();
            int len = q.size();
            for(int i = 0; i<len; ++i)
            {
                int u = q.front(); q.pop();
                ans.push_back(u);
                for(int a: adj[u])
                {
                    --indegree[a];
                    if(indegree[a]==1)
                        q.push(a);
               }
            }

        }
        
        return ans;
    }
};