class Solution {
public:
    void bfs(int v, unordered_map<int,vector<int>> & adj, vector<bool>&visited)
    {
        queue<int> q;
        q.push(v);
        visited[v] = true;
        while(!q.empty())
        {
            int u = q.front();q.pop();
            for(auto a:adj[u])
                if(!visited[a])
                {visited[a] = true; q.push(a);}
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>> > pq; //storing (indegree, vertex)
        vector<bool> visited(n,false);
        vector<int> indegree(n,0);
        vector<int> ans; ans.reserve(n);
        unordered_map<int,vector<int>> adj;
        for(auto e: edges)
        {
            ++indegree[e[1]];
            adj[e[0]].push_back(e[1]);
        }
        for(auto i = 0; i<n; i++) pq.push({indegree[i],i});
        
        while(!pq.empty())
        {
            int v = pq.top().second;
            int currIndegree = pq.top().first;
            pq.pop();
            if(!visited[v])
                {ans.push_back(v); bfs(v,adj,visited);}
        }
        
        return ans;
    }
};