class Solution {
public:
    //ALGO: We are using the concept of connected components in a graph (undirected one). Every email is basically connected to the other emails present in the same array.
    //For every unique user and all emails associated to him, there will be one single connected component in the graph we build using an adjacency list.
    //So if an email is present in multiple arrays, even when we connect that into the graph multiple times, its going to act like a single node only.
    
    //We perform DFS on every array's beginning email given in the accounts array. 
    //We are using an undirected graph just because it shouldn't matter from which node we begin our DFS,we should be able to cover all emails connected to a specific email, no matter from wherever we start.
    void dfs(string s, unordered_map<string,vector<string>> &mp, unordered_set<string>& visited, vector<vector<string>> & ans)
    {
        visited.insert(s);
        ans.back().push_back(s);
        
        for(auto i: mp[s])
        {
            if(visited.find(i)==visited.end())
                dfs(i,mp,visited,ans);
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        unordered_map<string, vector<string>> mp;
        unordered_set<string> visited;
        vector<vector<string>> ans;
        
        for(auto acc: accounts)
            for(auto i = 2; i<acc.size();i++)
            {
                mp[acc[i]].push_back(acc[i-1]);
                mp[acc[i-1]].push_back(acc[i]);
            }
        
        for(auto acc: accounts)
        {
           if(visited.find(acc[1])==visited.end())
           { ans.push_back({acc[0]});
             dfs(acc[1],mp,visited,ans);
            sort(ans.back().begin()+1, ans.back().end());
            }
        }
        
        return ans;
        
    }
};