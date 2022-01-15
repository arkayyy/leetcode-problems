class Solution {
public:
    int util(int idx, int dayCoveredTo, vector<int>& days, vector<int>& costs, vector<int>& dp)
    {
        if(idx==days.size()) return 0;
        
        if(days[idx]<=dayCoveredTo)
            return util(idx+1, dayCoveredTo, days, costs, dp);
        
        if(dp[days[idx]]!=-1) return dp[days[idx]];
        
        int mini = INT_MAX;
        mini = min(mini, costs[0]+util(idx+1, days[idx]+0,days,costs,dp)); // for 1-day pass
        mini = min(mini, costs[1]+util(idx+1, days[idx]+6,days,costs,dp)); // for 7-day pass
        mini = min(mini, costs[2]+util(idx+1, days[idx]+29,days,costs,dp)); //for 30-days pass
        
        return dp[days[idx]] = mini; //memoizing solution
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(380, -1);
        return util(0,0,days,costs,dp);
        
    }
};