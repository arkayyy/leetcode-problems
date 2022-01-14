class Solution {
public:
//     int util(int idx, vector<int>& coins, int amount, vector<vector<int>> &dp)
//     {
//         if(amount<0 || idx<0) return INT_MAX-1;
        
//         if(amount==0) return 0;
        
//         if(dp[amount][idx]!=INT_MAX) return dp[amount][idx];
        
//         return dp[amount][idx] = min( 1+util( idx, coins, amount-coins[idx],dp) , util(idx-1,coins,amount,dp));     
//     }
    int utilDP(vector<int>& coins, int amount)
    {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size()+1, INT_MAX-1));
        
        for(int j = 0; j<=coins.size(); j++)
            dp[0][j] = 0;
        
        for(int i = 1; i<=amount; i++)
        {
            for(int j = 1; j<=coins.size(); j++)
            {
                if(coins[j-1] > i) // means the coin amount is greater than the amount that needs to be made up, so we can't include it
                    dp[i][j] = dp[i][j-1];
                else
                    dp[i][j] = min(dp[i][j-1] , 1 + dp[i-coins[j-1]][j]);
                    
            }
        }
        return dp[amount][coins.size()];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(amount+1,vector<int>(coins.size()+1, INT_MAX));
        
       // int ans =  util(coins.size()-1,coins,amount, dp);
        int ans = utilDP(coins,amount);
        
        return (ans==INT_MAX-1?-1:ans);
    }
};