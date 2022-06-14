class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](const vector<int>&a,const vector<int>&b){
        return a[1]<b[1]; //sorting the intervals according to the end time (same as done in interview scheduling problems)
        });
        int prevEnd = intervals[0][1], ans = 0;
        for(int i= 1; i<intervals.size(); ++i)
        {
            if(intervals[i][0] < prevEnd) ++ans; //checking for current interval overlapping with the previous one
            else prevEnd = intervals[i][1]; 
        }
        return ans;
    }
};