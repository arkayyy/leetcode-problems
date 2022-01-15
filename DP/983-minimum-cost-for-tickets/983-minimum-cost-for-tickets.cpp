class Solution
{
    // EXPLANATION: https://leetcode.com/problems/minimum-cost-for-tickets/discuss/630868/explanation-from-someone-who-took-2-hours-to-solve
public:
    int util(int idx, int dayCoveredTo, vector<int> &days, vector<int> &costs, vector<int> &dp)
    {
        if (idx == days.size())
            return 0;

        if (days[idx] <= dayCoveredTo)
            return util(idx + 1, dayCoveredTo, days, costs, dp);

        if (dp[days[idx]] != -1)
            return dp[days[idx]];

        int mini = INT_MAX;
        mini = min(mini, costs[0] + util(idx + 1, days[idx] + 0, days, costs, dp));  // for 1-day pass
        mini = min(mini, costs[1] + util(idx + 1, days[idx] + 6, days, costs, dp));  // for 7-day pass
        mini = min(mini, costs[2] + util(idx + 1, days[idx] + 29, days, costs, dp)); // for 30-days pass

        return dp[days[idx]] = mini; // memoizing solution
    }

    int utilDPTable(vector<int> &days, vector<int> &costs)
    {
        vector<int> dp(380, 0);

        for (auto day : days)
            dp[day] = costs[0];
        for (int i = 1; i < 366; i++)
        {
            if (!dp[i])
                dp[i] = dp[i - 1];
            else
            {
                int j = max(0, i - 1);
                dp[i] = dp[j] + costs[0]; // for single day pass
                j = max(0, i - 7);
                dp[i] = min(dp[i], dp[j] + costs[1]); // for 7-day pass
                j = max(0, i - 30);
                dp[i] = min(dp[i], dp[j] + costs[2]); // for 30-day pass
            }
        }
        return dp[365];
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {

        vector<int> dp(380, -1); // size can be any number greater than 356
        // return util(0,0,days,costs,dp);

        return utilDPTable(days, costs);
    }
};