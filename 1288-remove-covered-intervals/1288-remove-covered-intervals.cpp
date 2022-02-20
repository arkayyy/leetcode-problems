class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
       
        sort(intervals.begin(), intervals.end());
        int cnt = 1;
         int a = intervals[0][0], b = intervals[0][1];
        for(int i = 1; i<intervals.size(); i++)
        {
            if(intervals[i][0]>a && intervals[i][1]>b)
               {cnt++; }
            if(intervals[i][1]>b)
            {
                a = intervals[i][0];
                b = intervals[i][1];
            }
           
            
        }
        return cnt;
    }
};