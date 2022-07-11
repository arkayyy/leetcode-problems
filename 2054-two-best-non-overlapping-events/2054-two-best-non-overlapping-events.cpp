class Solution {
public:
    vector<vector<int>> dp;
    int util(int i,int prevEnd,int prevIdx, vector<vector<int>>& events,int cnt)
    {
        if(i==events.size() || cnt==2) return 0;
        
        if(dp[cnt][i]!=-1) return dp[cnt][i];
        vector<int> t = {events[i][1],INT_MAX,INT_MAX};//for the next event to be considered, its starting time should be just greater than the current interval ending time
        int nidx = upper_bound(events.begin(),events.end(), t)-events.begin(); 
        
        int res = 0;
        //can include:-
        res = events[i][2]+util(nidx,events[i][1],i,events,cnt+1);
        //can't include:-
        res = max(res,util(i+1,prevEnd,prevIdx,events,cnt));
        
        return dp[cnt][i]=res;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        dp = vector<vector<int>>(2,vector<int>(events.size(),-1));
        sort(events.begin(),events.end());
        return util(0,-1,-1,events,0);
    }
};