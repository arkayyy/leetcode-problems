class Solution {
public:
    bool sufficientBouquets(vector<int>&bloom, int days, int m, int k)
        //will return if minimum m bouquets can be formed in <= days
    {
        int bqs = 0, cnt = 0;
        for(int i=0; i<bloom.size(); i++)
        {
            if(bloom[i]<=days)
                cnt++;
            else cnt = 0;
            if(cnt==k)
            {
                cnt = 0;
                bqs++;
            }
        }
        return bqs>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        if(k*m > bloomDay.size()) return -1;
        
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(),bloomDay.end());
        
        int mid;
        while(lo<=hi)
        {
            mid = lo+((hi-lo)>>1);
            if(sufficientBouquets(bloomDay,mid,m,k)) hi = mid-1;
            else lo=mid+1;
        }
        
        return lo;
        
    }
};