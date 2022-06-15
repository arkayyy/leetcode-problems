class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int peak = prices[0],valley = prices[0];
        int maxprofit = 0;int i=0;
        while(i<prices.size()-1)
        {
            while(i < prices.size()-1 && prices[i] >= prices[i+1])
                i++;
            valley = prices[i];
            while(i<prices.size()-1 && prices[i]<=prices[i+1])
                i++;
            peak = prices[i];
            maxprofit+= (peak-valley);
        }
        return maxprofit;
    }
};