class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int,vector<pair<int,double>>> adj;
        for(int i = 0; i<edges.size(); ++i)
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]}) , adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        
        priority_queue<pair<double,int>> pq;
        
        vector<double> dist(n, 0.00);
        dist[start] = 1.00;
        pq.push({1.0,start});
        
        bitset<10001> visited;
        
        while(!pq.empty())
        {
            int u = pq.top().second;
            double d = pq.top().first;
            pq.pop();
            if(visited[u]) continue;
            visited[u] = true;
            for(auto& a: adj[u])
            {
                int v = a.first; double w = a.second;
                if(d*w > dist[v])
                    {dist[v] = d*w; pq.push({dist[v],v});}
            }
        }
        
        
        return dist[end];
    }
};