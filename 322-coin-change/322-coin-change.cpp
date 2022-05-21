class Solution {
public:
    //Approach 1: Recursion + Memoization TC: O(n*amount) SC:O(n*amount)
    int util(int target,int idx, vector<int>&coins,vector<vector<int>>& dp)
    {
        if(target<0 || idx<0) return INT_MAX-1; 
        if(target==0) return 0;
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        int res = INT_MAX;
        for(int i = idx; i>=0; --i)
            res = min({res, 1+util(target-coins[i], i, coins,dp), util(target,i-1, coins,dp)});
        return dp[idx][target] = res;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end()); //sorting for greedily choosing least no. of coins first
        
        //===================Approach 1: Recursion + Memoization TC: O(n*amount) SC:O(n*amount)==========================//
        //vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1));
        // int ans = util(amount, coins.size()-1, coins, dp);
        // return ans==INT_MAX-1?-1:ans;
        
        
        //======================APPROACH 2: DP Tabulation TC:O(n*amount) SC:O(n*amount) no aux space=====================//
//         for(int j = 0; j<=amount; j++) dp[0][j] = INT_MAX-1;
//         for(int i = 0; i<=coins.size(); ++i) dp[i][0] = 0;
        
//         for(int i = 1; i<=coins.size(); ++i)
//             for(int j = 1; j<=amount; ++j)
//             {   
//                 dp[i][j] = dp[i-1][j];
//                 if(coins[i-1]<=j )
//                     dp[i][j] = min({dp[i][j], 1+dp[i][j-coins[i-1]]});
//             }
//         return dp[coins.size()][amount]==INT_MAX-1?-1:dp[coins.size()][amount];
        
        
        //=====================Space optimised DP Tabulation (since we only need current and previous row) SC:O(2*amount)=======================//
        vector<vector<int>> dp(2, vector<int>(amount+1));
        for(int j = 0; j<=amount; ++j) dp[0][j] = INT_MAX-1;
        dp[0][0] = 0;
        for(int i = 1; i<=coins.size(); ++i)
        {
            dp[1][0] = 0;
            for(int j = 1; j<=amount; ++j)
            {
                dp[1][j] = dp[0][j];
                if(coins[i-1]<=j)
                    dp[1][j] = min(dp[1][j], 1+dp[1][j-coins[i-1]]);
            }
            dp[0] = dp[1];
        }
        return dp[1][amount]==INT_MAX-1?-1:dp[1][amount];
    }
};