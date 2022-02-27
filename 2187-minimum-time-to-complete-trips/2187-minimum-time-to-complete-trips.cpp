class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
//         queue<pair<long long,long long>> q;
        
//         for(auto t: time)
//             q.push({t,0});
        
//         long long timeCounter = 0;
//         //long long inc = *min_element(time.begin(),time.end());
//         while(!q.empty())
//         {
//             long long len = q.size();
//             long long total = 0;
//             for(long long i = 0; i<len; i++)
//             {
//                 pair<long long,long long> t = q.front(); 
//                 q.pop();
//                 long long duration = t.first;
//                 long long freq = t.second;
//                 if( timeCounter >= (duration*freq + duration) )
//                    { q.push({duration,freq+1}); total+=(freq+1);}
//                 else
//                    { q.push({duration,freq}); total+=freq;}
//             }
            
//             if(total>=totalTrips)
//                 return timeCounter;
//             timeCounter++;
//         }
        sort(time.begin(),time.end());
        long long l = 0, r = 1e14;
        long long ans;
        while(l<=r)
        {
            long long mid = l+((r-l)/2);
            long long total = 0;
            for(int i = 0; i<time.size(); i++)
                total += (mid/time[i]);
            if(total>=totalTrips)
                {ans = mid; r = mid-1;}
            else
                l = mid+1;
        }
        
        return  ans;
    }
};