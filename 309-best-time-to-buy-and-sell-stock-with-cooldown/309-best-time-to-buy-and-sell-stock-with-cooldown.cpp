class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.size() < 2)
            return 0;
        int i, n = prices.size();
        int ans = 0;
        vector<int> buy(n, 0);
        vector<int> sell(n, 0);
        buy[0] = -prices[0];
        for (i = 1; i < n; ++i)
        {
            sell[i] = max(buy[i - 1] + prices[i], sell[i - 1] - prices[i - 1] + prices[i]);
            if (ans < sell[i]) 
                ans = sell[i];
            if (i==1)
                buy[i] = buy[0] + prices[0] - prices[1];
            else //doing sell[i-2] because one day is for cooldown period i.e. sell[i-1] can't be considered
                buy[i] = max(sell[i - 2] - prices[i], buy[i - 1] + prices[i - 1] - prices[i]);
        }
        return ans;
    }
};