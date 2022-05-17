class Solution {
public:
    //1-indexed disjoint set code (Using union by rank and path compression) ~ both unionBoth() and findParent() operations have O(1) time for n<=106400!
    class disjoint_set
    {
        private:
        int n;
        vector<int> parent, rank;
        
        public:
        disjoint_set(int n)
        {
            this->n = n;
            rank = vector<int>(n+1,0);
            parent = vector<int> (n+1,0);
            for(int i =1; i<=n; i++)
                parent[i] = i;
        }
        
        int findParent(int v)
        {
            if(v==parent[v]) return v;
            return parent[v] = findParent(parent[v]); //path compression
        }
        
        void unionBoth(int u, int v)
        {
            u = findParent(u);
            v = findParent(v);
            if(rank[u]<rank[v])
                parent[u] = v;
            else if(rank[v]<rank[u])
                parent[v] = u;
            else
                parent[v] = u, ++rank[u];
        }
        
        int countProvinces()
        {
            unordered_set<int> s(parent.begin(),parent.end());
            return s.size() - 1; //doing -1 because parent will be counted one extra time
        }
    };
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        disjoint_set d(n); //will create nodes from 1 to n inclusive
        for(auto i = 0; i<isConnected.size(); ++i)
        {
            for(auto j = 0; j<n; j++)
                if(isConnected[i][j])
                    d.unionBoth(i+1,j+1); //joining all nodes(wrt their components) as required
        }
        //doing this step because path compression might not have been called for each and every node before
        for(int i = 1; i<=n; i++)
            d.findParent(i);
        
        return d.countProvinces();
    }
};