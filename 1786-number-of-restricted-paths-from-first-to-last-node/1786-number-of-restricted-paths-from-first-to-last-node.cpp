class Solution {
public:
    int MOD = 1e9+7;
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<vector<int>>> adj;
        for(auto& e:edges)
            adj[e[0]].push_back({e[1],e[2]}), adj[e[1]].push_back({e[0],e[2]});
        
        vector<int> dist(n+1,INT_MAX), cnt(n+1,0);
        dist[n] = 0;
        cnt[n] = 1;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,n});
        while(!pq.empty())
        {
            int u = pq.top().second, d = pq.top().first; pq.pop();
            if(dist[u]<d) continue;
            for(auto& a: adj[u])
            {
                if(d+a[1] < dist[a[0]])
                {dist[a[0]] = d+a[1]; pq.push({dist[a[0]],a[0]});}
                if(d > dist[a[0]]) //if current path is longer(has more total weight) than the shortest path
                    cnt[u] = (cnt[u]+cnt[a[0]])%MOD;
            }
        }
        
        return cnt[1];
    }
};