class Solution {
public://INTUITION: Insert the new interval and then merge all the intervals together
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans(intervals.begin(),intervals.end());
        ans.push_back(newInterval); //inserting new interval
        sort(ans.begin(),ans.end());
        
        vector<vector<int>> finans;
        
        //merging all intervals:- (FOR EXPLANATION see Merge Intervals 56 on Leetcode, my YT channel and GitHub Repo - leetcode-problems)
        int left = ans[0][0], right = ans[0][1];
        for(int i = 1; i<ans.size(); i++)
        {   
            if(ans[i][0]<=right && ans[i][1]>right) 
                right = ans[i][1];
            
            else if(ans[i][0]>=left && ans[i][1]<=right) continue;
                
            else if(ans[i][0]>right) {finans.push_back({left,right}); left = ans[i][0]; right = ans[i][1];}
        }
        finans.push_back({left,right});
        
        return finans;
        
    }
};