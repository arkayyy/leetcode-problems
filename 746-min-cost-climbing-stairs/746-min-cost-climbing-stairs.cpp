class Solution {
public:
    //Recursion + Memoization -> Top-Down (going from 0th or 1st index to last). So in bottom-up approach we'll do the opposite!
    int util(int i, int n, vector<int>& cost,vector<int>&dp)
    {
        if(i>=n) return 0;
        
        if(dp[i]!=-1)return dp[i];
        
        return dp[i] = min(cost[i]+util(i+1,n,cost,dp), cost[i]+util(i+2,n,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
    
        int n = cost.size();
        if(n==2) return *min_element(cost.begin(), cost.end());
        // vector<int> dp(n,-1);
        // return min(util(0,n,cost,dp),util(1,n,cost,dp));
        
        //Tabulation DP (Bottom up):-
//         vector<int> dp(n+1,-1);
//         dp[n] = 0;
//         dp[n-1] = cost[n-1];
        
//         for(int i = n-2; i>=0; i--)
//             dp[i] = min(cost[i]+dp[i+1], cost[i]+dp[i+2]);
        
//         return min(dp[0],dp[1]);
        
        //Space optimised DP:-
        int twoStep = 0, oneStep = cost[n-1], curr;
        for(int i = n-2; i>=0; i--)
            {curr = min(cost[i]+oneStep, cost[i]+twoStep); twoStep = oneStep; oneStep = curr; }
        
        return min(oneStep, twoStep);
    }
};