class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        long long lo = 1, hi = target;
        long long pos;
        long long minSteps;
        while(lo<=hi)
        {
            long long mid = (lo+hi)/2;
            long long dist = (mid*(mid+1))/2;
            
            if(dist>=target)
            {
                pos= dist;
                minSteps = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        
        long long diff = pos - target;
        
        if(diff&1)//diff%2!=0 //diff = 0
        {
            if(minSteps&1)
                minSteps+=2;
            else
                minSteps+=1;
        }
        return minSteps;
    }
};