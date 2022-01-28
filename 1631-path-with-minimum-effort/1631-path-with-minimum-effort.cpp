class Solution {
public:
    void dfs(int i, int j, int diff, vector<vector<bool>>&visited, vector<vector<int>>&heights)
    {
        visited[i][j] = true;
        if(i==heights.size()-1 && j==heights[0].size()-1) return;
        
        if(i+1<heights.size() && !visited[i+1][j] && abs(heights[i][j]-heights[i+1][j])<=diff)
            dfs(i+1,j,diff,visited,heights);
        if(i-1>=0 && !visited[i-1][j] && abs(heights[i][j]-heights[i-1][j])<=diff)
            dfs(i-1,j,diff,visited,heights);
        if(j+1<heights[0].size() && !visited[i][j+1] && abs(heights[i][j]-heights[i][j+1])<=diff)
            dfs(i,j+1,diff,visited,heights);
        if(j-1>=0 && !visited[i][j-1] && abs(heights[i][j]-heights[i][j-1])<=diff)
            dfs(i,j-1,diff,visited,heights);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size(), m = heights[0].size();
        
        int lo = 0, hi;
        int maxi= INT_MIN, mini = INT_MAX;
        for(int i = 0; i<heights.size(); i++)
        {
            for(int j = 0; j<heights[0].size(); j++)
            {
                hi = max(hi, heights[i][j]);
            }
        }
        int ans;
        while(lo<=hi)
        {
            int mid = lo+((hi-lo)>>1);
            vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(),false));
            dfs(0,0,mid,visited,heights);
            if(visited[n-1][m-1])
            {
                ans = mid;
                hi = mid-1;
            }
            else
            {
                lo = mid+1;
            }
        }
        
        return lo;
    }
};