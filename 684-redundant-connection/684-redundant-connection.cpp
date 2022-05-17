class Solution {
public:
    class disjoint_set
    {
        private:
        vector<int> parent, rank;
        int n;
        
        public:
        disjoint_set(int n)
        {
            this->n = n;
            parent = vector<int>(n+1);
            rank = vector<int>(n+1,0);
            for(int i = 1; i<=n; ++i) parent[i] = i;
        }
        int findParent(int a)
        {
            if(parent[a]==a) return a;
            return parent[a] = findParent(parent[a]);
        }
        bool unionBoth(int a, int b)
        {
            a = findParent(a); b = findParent(b);
            if(a==b) return true; //cycle condition (new component being formed due to cycle)
            if(rank[a]<rank[b]) parent[a] = b;
            else if(rank[b]<rank[a]) parent[b] = a;
            else parent[b] = a, ++rank[a];
            
            return false;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        disjoint_set d(1000);
        for(auto e: edges)
        {
            if(d.unionBoth(e[0],e[1]))
                return e;
        }
        return {};
    }
};