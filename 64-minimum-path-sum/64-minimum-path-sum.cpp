class Solution {
public:
    int util(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(i==grid.size()-1 && j==grid[0].size()-1) return grid[i][j];
        if(i>=grid.size() || j>=grid[0].size()) return INT_MAX;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j] = grid[i][j]+min(util(i+1,j,grid,dp),util(i,j+1,grid,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        // vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),-1));
        // return util(0,0,grid,dp);
        
        vector<vector<int>> dp(grid.size()+1, vector<int>(grid[0].size()+1, INT_MAX));
        
        for(int i = grid.size()-1; i>=0; --i)
            for(int j = grid[0].size()-1; j>=0; --j)
            {
                if(i==grid.size()-1 && j==grid[0].size()-1) dp[i][j] = grid[i][j];
                else dp[i][j] = grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
                
        return dp[0][0];
    }
};