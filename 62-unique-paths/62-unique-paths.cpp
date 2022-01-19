class Solution {
public:
    int util(int i, int j, int& ans, vector<vector<bool>>& visited, vector<vector<int>> &dp)
    {
        if(i==visited.size()-1 && j==visited[0].size()-1) {ans++; return 1;}
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int res = 0;
        if(i+1<visited.size() && !visited[i+1][j])
        {
            visited[i+1][j] = true;
            int t=util(i+1,j,ans, visited,dp);
           // if(dp[i+1][j]==-1) dp[i+1][j] = t;
            res+=t;
            visited[i+1][j] = false;
        }
        
        if(j+1<visited[0].size() && !visited[i][j+1])
        {
            visited[i][j+1] = true;
            int t=util(i,j+1,ans,visited,dp);
            //if(dp[i][j+1]==-1) dp[i][j+1] = t;
            res+=t;
            visited[i][j+1] = false;
        }
        return dp[i][j] = res;
    }
    int uniquePaths(int m, int n) {
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return util(0,0,ans,visited,dp);
    }
};