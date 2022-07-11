class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<long long,vector<pair<long long,long long>>> adj;
        for(auto &r:roads)
            adj[r[0]].push_back({r[1],r[2]}), adj[r[1]].push_back({r[0],r[2]});
        
        vector<long long> dist(n,LLONG_MAX), ways(n,0);
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>> , greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        dist[0] = 0, ways[0] = 1;
        
        
        int MOD = 1e9+7;
        while(!pq.empty())
        {
            long long u = pq.top().second,d = pq.top().first; pq.pop();
            if(dist[u]<d) continue;
            for(auto&a: adj[u])
            {
                long long v = a.first, w = a.second;
                if(d+w<dist[v])
                {dist[v] = d+w; ways[v] = ways[u]; pq.push({dist[v],v});}
                else if(d+w==dist[v])
                    ways[v] = (ways[v]+ways[u])%MOD;
            }
        }
        return ways[n-1];
    }
};