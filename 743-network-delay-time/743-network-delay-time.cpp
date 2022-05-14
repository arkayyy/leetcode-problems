class Solution {
public:
    //ALGO: Simple BFS based Djikstra to reach all nodes!
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        vector<int> dis(n+1,INT_MAX);
        vector<bool> visited(n+1,false);
        
        for(auto t: times)
            adj[t[0]].push_back({t[1],t[2]});
        
        dis[k] = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.emplace(0, k);
        
        while (!pq.empty()) {
            int u = pq.top().second; pq.pop();
			if (visited[u]) continue;
			visited[u] = true;
            for (auto& a : adj[u]) {
                int v = a.first, w = a.second;
                if (dis[v] > dis[u] + w) { //checking if it can be relaxed (relaxation condition)
                    dis[v] = dis[u] + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        int ans = *max_element(dis.begin() + 1, dis.end());
        return ans == INT_MAX ? -1 : ans;
    }
};