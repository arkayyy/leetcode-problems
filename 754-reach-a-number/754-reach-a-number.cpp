class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        long long lo = 1, hi = target; // moves: [1,target]
        long long pos;
        long long minSteps = INT_MAX;
        while(lo<=hi)
        {
            long long mid = lo+((hi-lo)>>1);
            if( ((mid*(mid+1))>>1) >= target)
            {
                pos = ((mid*(mid+1))>>1); // the pos
                minSteps = mid; //mid -> no. of moves
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        
        long long diff = pos-target; 
        
        if(diff&1)
        {
            if(minSteps&1)
            {
                minSteps+=2;
            }
            else
                minSteps+=1;
        }
        
        return minSteps;
        
    }
};