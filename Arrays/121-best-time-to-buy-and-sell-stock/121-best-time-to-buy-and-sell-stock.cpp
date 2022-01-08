class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // ALGO: we store the minimum element encountered till now, and the maximum profit encountered till now in two separate variables
        int mini = INT_MAX;
        int maxProfit = 0; // initialising with 0, since even if there's no chance of selling for max profit, the profit can't be negative as per question (ie. if we can't achieve profit we have to return 0)

        for (auto p : prices)
        {
            if (p < mini)
                mini = p;
            else if (p - mini > maxProfit)
                maxProfit = p - mini;
        }

        return maxProfit;
    }
};