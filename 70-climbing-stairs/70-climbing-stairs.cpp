class Solution {
public:
    //Recursion + Memoization -> Gives TLE
    int util(int n, vector<int>& dp)
    {
        if(n<0) return 0;
        
        if(n==0) return 1;
        
        if(dp[n]!=-1) return dp[n];
        
        return dp[n] = climbStairs(n-1)+climbStairs(n-2);
    }
    int climbStairs(int n) {
        //Tabulation DP:-
//         vector<int> dp(n+1,-1);
        
//         dp[0] = 0;
//         dp[1] = 1;
//         for(int i = 2; i<=n; i++)
//             dp[i] = dp[i-1]+dp[i-2];
        
//         return dp[n]+dp[n-1];
        
        //Space optimised DP:-
        if(n==1||n==2) return n;
        int prev2 = 0, prev1 = 1;
        int curr = 0;
        for(int i = 2; i<=n; i++)
        {curr = prev1+prev2; prev2=prev1; prev1 = curr;}
        
        return curr + prev2;
    }
};