class Solution {
public:
    int trap(vector<int>& height) {
        int lo = 0, hi = height.size()-1;
        int lmax = INT_MIN, rmax = INT_MIN;
        int ans = 0;
        while(lo<hi)
        {
            if(height[hi]<height[lo]) //if height at hi index is lower, letting flow from the lower height first
            {
                if(height[hi]>rmax) rmax = height[hi];
                else ans += (rmax - height[hi]);
                hi--;
            }
            else //if height at lo index is lower (or equal) we let water flow from this side
            {
                if(height[lo]>lmax) lmax = height[lo];
                else ans += (lmax-height[lo]);
                lo++;
            }
        }
        return ans;
    }
};