class Solution {
public:
    double totalTime(vector<int>&dist, int speed)
    {
        double time = 0.;
        for(int i = 0; i<dist.size()-1; i++)
        {
            time+= ceil((double)dist[i]/(double)speed);
        }
        time+= ((double)dist[dist.size()-1]/(double)speed);
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int lo = 1, hi = 1e7;
        int mid;
        //double minTime = 0.;
        int ans = -1;
        while(lo<=hi)
        {
            mid = (lo+((hi-lo)>>1));
            double time = totalTime(dist,mid);
            cout<<time<<endl;
            if(time<=hour)
            {
                ans = mid;
                hi = mid-1;
                //minTime = time;
            }
            else
                lo = mid+1;
        }
        return ans;
    }
};