class Solution {
public:
    int util(int n, vector<int>& cost,vector<int>&dp)
    {
        if(n<=0) return 0;
        
        if(dp[n]!=-1)return dp[n];
        
        return dp[n] = min(cost[n-1]+util(n-1,cost,dp), cost[n-1]+util(n-2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return min(util(n-1,cost,dp),util(n,cost,dp));
    }
};