class Solution {
public:
    int util(int i, int n, vector<int>& cost,vector<int>&dp)
    {
        if(i>=n) return 0;
        
        if(dp[i]!=-1)return dp[i];
        
        return dp[i] = min(cost[i]+util(i+1,n,cost,dp), cost[i]+util(i+2,n,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(util(0,n,cost,dp),util(1,n,cost,dp));
    }
};