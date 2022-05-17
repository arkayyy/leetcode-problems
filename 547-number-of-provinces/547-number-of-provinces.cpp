class Solution {
public:
    //1-indexed disjoint set code
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
            return parent[v] = findParent(parent[v]);
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
            return s.size() - 1;
        }
    };
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        disjoint_set d(n); //will create nodes from 1 to n inclusive
        for(auto i = 0; i<isConnected.size(); ++i)
        {
            for(auto j = 0; j<n; j++)
                if(isConnected[i][j])
                    d.unionBoth(i+1,j+1);
        }
        
        for(int i = 1; i<=n; i++)
            d.findParent(i);
        
        return d.countProvinces();
    }
};