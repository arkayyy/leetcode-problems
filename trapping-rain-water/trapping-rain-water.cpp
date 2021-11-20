class Solution {
public:
    int trap(vector<int>& height) {
        
        
        
        int lo = 0, hi = height.size()-1;
        int lmax = INT_MIN, rmax = INT_MIN;
        int ans = 0;
        while(lo<hi)
        {
            if(height[hi]<height[lo])
            {
                if(height[hi]>rmax)
                    rmax = height[hi];
                else
                    ans += (rmax - height[hi]);
                
                hi--;
            }
            else
            {
                if(height[lo]>lmax)
                    lmax = height[lo];
                else
                    ans += (lmax-height[lo]);
                
                lo++;
            }
        }
        
        return ans;
    }
};