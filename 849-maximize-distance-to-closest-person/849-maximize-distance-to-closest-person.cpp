class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        //INTUITION: Same as exam room problem, we have three types of gaps (consecutive empty seats) here. 
        //1. At the starting,  before the firsmost occupied seat
        //2. In the middle of two occupied seats
        //3. At the end, after the lastmost occupied seat
        //Thus we need to calculate in which case the distance produced would be maximum
        //Also remember that in a series of empty chairs between two occupants, in order to maximise distance from both of them we sit at the middle.
        
        //ALGO:We find the starting gap, middle gap (maximum of all the middle gaps) and ending gap. We check which one produces maximum distance.
        int prev=0;
        int maxGapFirst = INT_MIN, maxGapBetween = INT_MIN, maxGapEnd = INT_MIN;
        int a=-1,b=-1;
        
        for(prev = 0; prev<seats.size(); prev++)
        {
            if(seats[prev]==1)
            {
                break;
            }
        }
        int start = prev;
        maxGapFirst = prev - 0;
        
        for(int i=start+1; i<seats.size();i++)
        {
            if(seats[i]==1)
            {             
                if(i-prev-1>0 && i-prev-1 > maxGapBetween) 
                {maxGapBetween = i-prev-1; a = prev; b = i; }
                
                prev = i;
            }
        }
        //calculating the distance produced if the person is seated right in the middle of the two occupants
        int distForMaxGapBetween;
        if(maxGapBetween&1)
            distForMaxGapBetween = max(abs(((a+b)>>1)-a), abs(((a+b)>>1)-b));
        else
            distForMaxGapBetween= max(abs(((a+b)>>1)-a)-1, abs(((a+b)>>1)-b)-1);
        
        maxGapEnd = seats.size()-1 - prev;
        
        
        int maxGap = max({maxGapFirst, distForMaxGapBetween, maxGapEnd});
        
        
        if(maxGap == maxGapFirst) return start-0;
        
        if(maxGap == maxGapEnd) return seats.size()-1-prev;
    
    
        return distForMaxGapBetween;
        
    }
};