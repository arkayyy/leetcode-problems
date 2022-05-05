class Solution {
public:
    //Recursion + Memoization fn. -> Going top-down and memoizing max profit related to indexes as (day, transactions left)
    //Top down -> days from 0 to n, transactions from 4 to 0
    //So bottom up -> days from n to 0, transactions from 0 to 4
    int util(int day, int transactions, vector<int>&prices, vector<vector<int>>& dp)
    {
        if(day==prices.size())
            return 0;
        if(transactions==0)
            return 0;
    
        if(dp[day][transactions]!=-1) return dp[day][transactions];
        
        //if we don't transact with the current index share
        int dontBuy = util(day+1, transactions, prices,dp);
        
        //if we transact the current index share
        int buy;
        int shouldBuy = transactions%2==0; //since we can only one share at once, and buy another only after we sell that one.
        //e.g. we have all 4 transactions left means, we can only buy share. 
        //and when we have 3 left, means we have already bought one, so we can only sell before we buty another.
        if(shouldBuy)
            buy = -prices[day]+util(day+1, transactions-1, prices,dp);
        else
            buy = prices[day]+util(day+1, transactions-1, prices,dp);
        
        return dp[day][transactions] = max(dontBuy, buy);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        //===============================APPROACH 1: Recursion + Memoization ==================================//
        // int transactions = 4; //2 selling + 2 buying transactions (We buy when transactions value is even, and sell when it is odd)
        // vector<vector<int>> dp(n,vector<int>(transactions+1,-1));
        // return util(0,transactions,prices,dp);
        
        
        //===============================APPROACH 2: Tabulation DP ===========================================//
        int transactions = 4;  //2 selling + 2 buying transactions (We buy when transactions value is even, and sell when it is odd)
        vector<vector<int>> dp(n+1,vector<int>(transactions+1,-1));
        
        for(int t = 0; t<=transactions; t++)
            dp[n][t] = 0;
        for(int d = 0; d<=n; d++)
            dp[d][0] = 0;
        
        for(int days = n-1; days>=0; days--)
        {
            for(int t = 1; t<=4; t++)
            {
                int dontBuy = dp[days+1][t];
        
                //if we transact the current index share
                int buy;
                int shouldBuy = t%2==0; //since we can only one share at once, and buy another only after we sell that one.
                //e.g. we have all 4 transactions left means, we can only buy share. 
                //and when we have 3 left, means we have already bought one, so we can only sell before we buty another.
                if(shouldBuy)
                    buy = -prices[days]+dp[days+1][t-1];
                else
                    buy = prices[days]+dp[days+1][t-1];

                dp[days][t] = max(dontBuy, buy);
            }
        }

        return dp[0][4];
    }
};