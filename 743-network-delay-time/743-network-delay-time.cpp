class Solution {
public:
    //======================APPROACH 1: Simple BFS based Djikstra to reach all nodes! TC: O(NlogN + E) SC:O(N+E)==========================//
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //unordered_map<int,vector<pair<int,int>>> adj;
        vector<long long> dis(n+1,LLONG_MAX);
//         vector<bool> visited(n+1,false);
        
//         for(auto t: times)
//             adj[t[0]].push_back({t[1],t[2]});
        
//         dis[k] = 0;
        
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
//         pq.emplace(0, k);
        
//         while (!pq.empty()) {
//             int u = pq.top().second; pq.pop();
// 			if (visited[u]) continue;
// 			visited[u] = true;
//             for (auto& a : adj[u]) {
//                 int v = a.first, w = a.second;
//                 if (dis[v] > dis[u] + w) { //checking if it can be relaxed (relaxation condition)
//                     dis[v] = dis[u] + w;
//                     pq.emplace(dis[v], v);
//                 }
//             }
//         }
//         int ans = *max_element(dis.begin() + 1, dis.end());
//         return ans == LLONG_MAX ? -1 : ans;
        
        //======================APPROACH 2: Bellman Ford Algo TC: avg: O(NE) worst: O(N^3) SC:(N)==========================//
        dis[k] = 0;
        for(int i = 1; i<=n; i++)
            for(auto t: times)
               {if(dis[t[0]]==LLONG_MAX) continue;
                dis[t[1]] = min(dis[t[1]], dis[t[0]]+t[2]);}
        int ans = *max_element(dis.begin() + 1, dis.end());
        return ans == LLONG_MAX ? -1 : ans;
        
        
    }
};