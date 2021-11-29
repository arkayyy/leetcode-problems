class Solution {
public:
    void dfs(int v,int n, vector<int> curr, vector<vector<int>>& ans, vector<vector<int>>&graph)
    {
        if(v==n-1)
            ans.push_back(curr);
        
        for(auto i: graph[v])
        {
            curr.push_back(i);
            dfs(i,n,curr,ans,graph);
            curr.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        
        dfs(0,graph.size(),{0},ans,graph);
        return ans;
    }
};