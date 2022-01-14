class Solution {
public:
    int util(int idx, vector<int>& coins, int amount, vector<vector<int>> &dp)
    {
        if(amount<0 || idx>coins.size()-1) return INT_MAX-1;
        
        if(amount==0) return 0;
        
        if(dp[amount][idx]!=INT_MAX) return dp[amount][idx];
        
        return dp[amount][idx] = min( 1+util( idx, coins, amount-coins[idx],dp) , util(idx+1,coins,amount,dp));     
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(amount+1,vector<int>(coins.size()+1, INT_MAX));
        
        int ans =  util(0,coins,amount, dp);
        
        return (ans==INT_MAX-1?-1:ans);
    }
};