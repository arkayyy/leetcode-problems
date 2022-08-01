class Solution {
public:
    int uniquePaths(int m, int n) { 
        
        // int total = m+n-2;
        // int r = n-1;
        // double ans = 1;
        // for(int i = 1; i<=r; i++)
        // {
        //     ans = ans*(total-r+i)/i;
        // }
        // return (int)ans;
        
        //===========================APPROACH 1: Tabulation DP O(MN) Time O(MN) Space=============================================//
        //INTUITION: In Bottom Up approach, at any point the max number of unique paths would be the sum of max unique paths to its top cell + max unique paths to its left cell...
        //since the robot can only move in bottom and right cell in Top Down Approach (can be done through recursion+memoization)
        // vector<vector<int>>dp (m,vector<int>(n,0));
        // for(int i = 0; i<m; i++)
        //     for(int j = 0;j<n; j++)
        //     {
        //         if(i==0 || j==0) dp[i][j] = 1;
        //         else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        //     }
        // return dp[m-1][n-1];
        
        //============================APPROACH 2: Space optimised DP O(MN) Time O(2N)Space =============================================//
        //Since only current and previous rows of dp array are being required at every step...
        vector<vector<int>> dp(2, vector<int>(n,1));
        for(int i = 1; i<m; i++)
        {
            for(int j = 1; j<n; j++)
            {
                dp[1][j] = dp[0][j]+dp[1][j-1]; 
            }
            dp[0] = dp[1];
        }

        return dp[1][n-1];
    }
};