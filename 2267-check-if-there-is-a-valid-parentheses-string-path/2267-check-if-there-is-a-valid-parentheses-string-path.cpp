class Solution {
public:
    int dp[100][100][201];
    int n,m;
    bool util(vector<vector<char>>& grid, int i, int j, int bal)
    {
        if(i>=n || j>=m) return 0;
        bal += grid[i][j]=='('?1:-1;
        if(bal<0) return 0;
        if(i==n-1 && j==m-1) return !bal;
        if(dp[i][j][bal]!=-1) return dp[i][j][bal];
        return dp[i][j][bal] = util(grid,i+1,j,bal)||util(grid,i,j+1,bal);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return util(grid,0,0,0);
    }
};