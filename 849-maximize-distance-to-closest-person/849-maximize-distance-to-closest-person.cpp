class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
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
        //cout<<maxGapFirst<<endl;
        
        for(int i=start+1; i<seats.size();i++)
        {
            if(seats[i]==1)
            {             
                if(i-prev-1>0 && i-prev-1 > maxGapBetween) 
                {maxGapBetween = i-prev-1; a = prev; b = i; }
                
                prev = i;
            }
        }
        //cout<<maxGapBetween<<endl;
        if(maxGapBetween&1)
            maxGapBetween = max(abs(((a+b)>>1)-a), abs(((a+b)>>1)-b));
        else
            maxGapBetween= max(abs(((a+b)>>1)-a)-1, abs(((a+b)>>1)-b)-1);
        
        maxGapEnd = seats.size()-1 - prev;
        //cout<<maxGapEnd<<endl;
        
        int maxGap = max({maxGapFirst, maxGapBetween, maxGapEnd});
        
        
        if(maxGap == maxGapFirst) return start-0;
        
        if(maxGap == maxGapEnd) return seats.size()-1-prev;
        cout<<a<<"->"<<b<<endl;
        //if(maxGap == maxGapBetween) 
        return maxGapBetween;
        
    }
};