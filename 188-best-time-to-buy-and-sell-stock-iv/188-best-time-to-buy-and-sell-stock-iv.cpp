class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int transactions = 2*k;  //taking both buy and sell transactions total
        vector<vector<int>> dp(n+1,vector<int>(transactions+1,-1));
        
        //step 1: base case transfer as per the ones used in recursion+memoization
        for(int t = 0; t<=transactions; t++)
            dp[n][t] = 0;
        for(int d = 0; d<=n; d++)
            dp[d][0] = 0;
        //step 2: recurrence relations similar as per the ones used in recursion+memoization
        for(int days = n-1; days>=0; days--)
        {
            for(int t = 1; t<=transactions; t++)
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

        return dp[0][transactions];
    }
};