class Solution {
    typedef pair<int, int> PII;
public:
    int countRestrictedPaths(int n, vector<vector<int>>& E) {
        long mod = 1e9 + 7;
        vector<vector<pair<long, int>>> G(n);
        for (auto &e : E) {
            int u = e[0] - 1, v = e[1] - 1, w = e[2];
            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
        }
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        vector<long> dist(n, INT_MAX), cnt(n, 0);
        dist[n - 1] = 0;
        cnt[n - 1] = 1;
        pq.emplace(0, n - 1);
        while (pq.size()) {
            auto [w, u] = pq.top();
            pq.pop();
            if (w > dist[u]) continue;
            for (auto &[v, d] : G[u]) {
                if (dist[v] > w + d) {
                    dist[v] = w + d;
                    pq.emplace(dist[v], v);
                }
                if (w > dist[v]) {
                    cnt[u] = (cnt[u] + cnt[v]) % mod;
                }
            }
        }
        return cnt[0];
    }
};