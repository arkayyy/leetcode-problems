class Solution {
    //INTUITION: Binary search on the speed, shifting range to lesser everytime the time criteria is fulfilled, so as to find the min. speed meeting the criteria.
    
    //ALGO: For every speed found through binary search, we calculate the total time required for covering all the distances. 
    //Everytime we get a speed that meets the criteria totalTime<=hour, we store that speed and try to minimise the speed by shoifting the range of binary search to the lower range (i.e range shifted to: lo to mid-1)
    //So ultimately we have the min. speed that meets the criteria given
    
public:
    double totalTime(vector<int>&dist, int speed)
    {
        double time = 0.;
        for(int i = 0; i<dist.size()-1; i++)
        {
            time+= ceil((double)dist[i]/(double)speed); //taking ceil for first n-1 elements because we can take only integer intervals
        }
        time+= ((double)dist[dist.size()-1]/(double)speed); // for the last distance only decimal time needs to be taken to avoid miscalculation
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int lo = 1, hi = 1e7;
        int mid;
        int ans = -1;
        while(lo<=hi)
        {
            mid = (lo+((hi-lo)>>1));
            double time = totalTime(dist,mid);
           // cout<<time<<endl;
            if(time<=hour)
            {
                ans = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        return ans;
    }
};