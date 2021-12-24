class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        int left = -1, right = -1;
        
        sort(intervals.begin(),intervals.end()); //sorting to enhance our soln.
        
        left = intervals[0][0];
        right = intervals[0][1];
        
        for(int i = 1; i<intervals.size();i++)
        {
            if(intervals[i][0] > right) //CASE I: if current {left,right} is {1,3} and the ith element (range) is {4,6}..
                //then {1,3} will be pushed into ans and 4,6 will be set as the new left,right
            {
                ans.push_back({left,right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
            else if(intervals[i][0]<right && intervals[i][1]<right)
            //CASE II: if current {left,right} is {1,5} and ith interval is {2,4} which is totally within {1,5}, then {left,right} would stay as it is
            {
                continue;
            }
            else//CASE III: the case if {left,right} is {1,4} and ith interval is {2,5}, the right would be set as the highest one, i.e. right = 5.
            {
                right = intervals[i][1];
            }
        }
        
        //pushing the last interval
        ans.push_back({left,right});
        
        return ans;
    }
};