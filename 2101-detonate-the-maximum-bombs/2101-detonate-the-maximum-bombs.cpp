class Solution {
public:
    
    int util(int v, unordered_map<int,vector<int>>& adj, set<int>& blasted)
    {
        if(!blasted.count(v))
        {
            blasted.insert(v);
            for(auto&a: adj[v])
                util(a,adj,blasted);
        }
        return blasted.size();          
    }

    bool isInside(vector<int>&b1, vector<int>&b2)
    {
        return (long long)pow(b1[0]-b2[0],2)+(long long)pow(b1[1]-b2[1],2)<=(long long)pow(b1[2],2);
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int,vector<int>> adj;
        for(int i = 0; i<bombs.size(); ++i)
        {
            for(int j = 0; j<bombs.size(); ++j)
                if(i!=j && isInside(bombs[i],bombs[j]))
                    adj[i].emplace_back(j);
        }
        
        int ans = 0;
        queue<int> q;
        
        for(int i = 0; i<bombs.size(); ++i)
        {
            set<int> blasted;
            ans = max(ans, util(i,adj,blasted));
        }
        return ans;
    }
};