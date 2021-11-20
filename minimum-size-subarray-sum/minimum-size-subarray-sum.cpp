class Solution {
public:
    bool slidingWindow(int size,int target, vector<int>& prefixSum)
    {
        int n = prefixSum.size();
        
        for(int i = 0; (i+size)<n;i++)
        {
            if(prefixSum[i+size]-prefixSum[i] >= target)
                return true;
        }
        
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        vector<int>prefixSum(n+1,0);
        for(int i = 1; i<=n;i++)
        {
            prefixSum[i] += (prefixSum[i-1]+nums[i-1]);
        }
        
        int lo = 0, hi = n;
        int ans = INT_MAX;
        int mid = INT_MAX;
        
        while(lo<=hi)
        {
            mid = (lo+((hi-lo)>>1));
            
            if(slidingWindow(mid,target,prefixSum))
                {ans = min(ans,mid); hi = mid-1;}
            else
                lo = mid+1;
        }
        if(ans==INT_MAX)
            return 0; //no such subarray exists
        return ans;
    }
};