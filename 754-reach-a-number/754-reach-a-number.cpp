class Solution {
public:
    int reachNumber(int target) {
                
        target = abs(target); //essential: either it be on positive or negative side, it would produce no difference
        
        long long lo = 1, hi = target; //minimum we can take is 1 steps and maximum is 'target' steps
        long long minPos = LLONG_MAX;
        long long minSteps= LLONG_MAX;

        while(lo<=hi)
        {
            long long mid = lo+((hi-lo)>>1);
            long long dist = ((mid*(mid+1))>>1); //distance covered starting from 1 by taking mid steps
            //since steps are of distances like 1,2,3,4... so the total dist covered = n*(n+1)/2 
            long long finPos = dist; //since we start from 0, final position will be dist ahead of 0
            if(finPos>=target)
            {
                minSteps = min(minSteps,mid);
                minPos = min(minPos,finPos);
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        //difference b/w min position ahead of target reached and the target positions
        long long diff = target - minPos;
        //if this difference is:-
        //1) 0(zero): no need of doing anything since we have already reached our target
        //2) even : no need of doing anything, dry run and see that the second last step can be flipped in order to reach the target seamlessly
        //3) odd: we need to convert this difference into even. 
        //---3.1)If minSteps taken is already odd, the next(additional) step would produce even distance, that means new distance from the target would be odd+even = odd distance again, so we need to do one more step to make this diff even. So 2 additional steps in total.
        //---3.2)If minSteps is even, the next(additional) step would product odd distance, so new distance from target = odd+odd = even. HURRAH! So 1 additional step in total.
        
        if(diff&1)
            return (minSteps&1)?(minSteps+2):(minSteps+1);
        
        return minSteps;
            
    }
};