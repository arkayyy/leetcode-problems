class Solution {
public:
    //Same as Unbounded Knapsack Problem
    int utilDP(vector<int>& coins, int amount)
    {
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        for(int i = 1; i<=amount; i++) // looping through every possible amount 
        {
            for(int j = 0; j<coins.size(); j++) // checking each and every coin for every value of amount that needs to be summed up to
            {
                if(coins[j]<=i) // only if the coin is of value less than the amount that needs to be summed up to
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]); 
            }
        }
        
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = utilDP(coins,amount);
        return (ans==INT_MAX-1? -1 : ans);
    }
};