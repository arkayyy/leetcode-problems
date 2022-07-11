class Solution {
public:
    bool isCyclic(int v, vector<vector<int>>& graph, vector<int>&visited)
    {
        if(visited[v]==1) return true;
        
        if(visited[v]==0)
        {
            visited[v] = 1;
            for(auto&a:graph[v])
            {
                if(isCyclic(a,graph,visited))
                    return true;
            }
        }
        
        
        visited[v] = 2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //INTUITION: We have to find the nodes that are not in a cycle, because otherwise they won't lead to a terminal node in any way
        int n=graph.size();
        vector<int> ans;
        vector<int> visited(graph.size(),0);
        
        for(int i = 0; i<n;++i)
            if(visited[i]==2 || !isCyclic(i,graph,visited))
                ans.emplace_back(i);
        
        return ans;
                
    }
};