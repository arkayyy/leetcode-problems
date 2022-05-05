class Solution {
public:
    int util(int day, int transactions, vector<int>&prices, vector<vector<int>>& dp)
    {
        if(day==prices.size())
            return 0;
        if(transactions==0)
            return 0;
    
        if(dp[day][transactions]!=-1) return dp[day][transactions];
        
        int dontBuy = util(day+1, transactions, prices,dp);
        
        int buy;
        int shouldBuy = transactions%2==0;
        if(shouldBuy)
            buy = -prices[day]+util(day+1, transactions-1, prices,dp);
        else
            buy = prices[day]+util(day+1, transactions-1, prices,dp);
        
        return dp[day][transactions] = max(dontBuy, buy);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int transactions = 4; //2 selling and 2 buying (We buy when transactions value is even, and sell when it is odd)
        vector<vector<int>> dp(n,vector<int>(transactions+1,-1));
        return util(0,transactions,prices,dp);
    }
};