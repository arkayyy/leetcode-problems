class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int maxProfit=0;
        for(auto i:prices)
        {
            if(i<mini)
                mini=i;
            else if(i-mini>maxProfit)
                maxProfit=i-mini;
        }
        
        return maxProfit;
    }
};