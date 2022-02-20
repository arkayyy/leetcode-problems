class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
       //INTUITION: Merge intervals concept
        sort(intervals.begin(), intervals.end());
        int cnt = 1;
         int a = intervals[0][0], b = intervals[0][1];
        for(int i = 1; i<intervals.size(); i++)
        {
            if(intervals[i][0]>a && intervals[i][1]>b) //counting number of intervals to be considered finally
               {cnt++; }
            if(intervals[i][1]>b) //if intervals[i][1]<=b, we can continue with the same interval
            {
                a = intervals[i][0];
                b = intervals[i][1];
            }
           
            
        }
        return cnt;
    }
};