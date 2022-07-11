class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        unordered_map<int,vector<int>> adj;
        for(auto&e:edges)
        {
            adj[e[0]].push_back(e[1]); adj[e[1]].push_back(e[0]);
        }
        vector<int> time(patience.size(),INT_MAX);
        time[0] = 0;
        queue<int> q;
        int timer = 0;
        q.push(0);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto&a:adj[u])
                if(time[a]==INT_MAX)
                {
                    time[a] = time[u]+1;
                    q.push(a);
                }
        }
        int res = 0;
        for(int i = 1; i<patience.size(); ++i)
        {
            int resends = (time[i]*2 - 1)/patience[i];
            int lastOut = resends*patience[i]; //time of last resend
            int lastIn = lastOut+time[i]*2; // time when last resend comes back
            res = max(res,lastIn);
        }
        return res+1;
    }
};