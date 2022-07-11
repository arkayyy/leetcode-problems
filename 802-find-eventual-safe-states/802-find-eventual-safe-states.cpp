class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>& color,int node)
    {
        if(color[node]==1) return true;
        
        
        if(color[node]==0)
        {
            color[node] = 1;
            for(auto cur : graph[node])
            if(dfs(graph,color,cur))
                return true;
        }
        
        
        color[node]=2;  // If there is no cycle mark node as safe.
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> color(graph.size()),result;
		
		// If node is visited and safe or unvisited and does not contain cycle then add it to the answer.
        for(int i=0;i<graph.size();i++)
            if(color[i]==2 ||  !dfs(graph,color,i))
                result.push_back(i);
                
        return result;
    }
};