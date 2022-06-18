class Solution {
public:
    //INTUITION: Go through every route and calc the min. sum. We can store the min. sum attained starting from a specific index by memoizing.
    int dfs(int i, int j,vector<vector<int>>& dp, vector<vector<int>>& grid)
    {
        if(i==grid.size()-1 && j==grid[0].size()-1) return grid[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j]; //if value is already memoized, it means this path's min value has already been computed starting from (i,j)
        
        int mini = INT_MAX;
        
        if(i+1<grid.size())
            mini = min(mini, grid[i][j]+dfs(i+1,j,dp,grid)); //moving down
        if(j+1<grid[0].size())
            mini = min(mini, grid[i][j]+dfs(i,j+1,dp,grid)); //moving right
        
        return dp[i][j] = mini;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int minSum = INT_MAX;
        // vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        // return dfs(0,0,dp,grid);
        
        //TABULATION DP:-
        vector<vector<int>> dp(grid.begin(),grid.end());
        int r = grid.size(), c = grid[0].size();
        for(int i = 1; i<r; i++)
            dp[i][0] += dp[i-1][0]; //in 0th column, the path can come only from above, so adding the current value with the previous row value
        for(int j = 1; j<c; j++)
            dp[0][j] += dp[0][j-1]; //in 0th row, the path can come only from left, so adding the current value with the previous column value
        
        for(int i= 1; i<r; i++)
            for(int j = 1; j<c;j++)
                dp[i][j] += min(dp[i-1][j], dp[i][j-1]); //addding the minimum of path from above and left to the current val
        
        return dp[r-1][c-1];
    }
};