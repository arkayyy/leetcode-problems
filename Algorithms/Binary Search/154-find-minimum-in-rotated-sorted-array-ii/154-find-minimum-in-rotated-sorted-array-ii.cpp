class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return min(nums[0], nums[1]);
        if(nums[n-1] > nums[0]) return nums[0];
       
        int lo = 0, hi = nums.size()-1;
        while(lo<=hi)
        {   
            //for repetitions
            while(lo+1<nums.size() && nums[lo]==nums[lo+1]) lo++;
            while(hi-1>=0 && nums[hi]==nums[hi-1]) hi--;
            
            int mid = lo+((hi-lo)>>1);
            
            //checking on left and right side of nums[mid], in order to determine if nums[mid] is itself the minimum element/pivot
            if(mid-1>=0 && nums[mid]<nums[mid-1]) return nums[mid];
            if(mid+1<nums.size() && nums[mid+1]<nums[mid]) return nums[mid+1];
            
            //changing the ranges otherwise to wherever increasing order is not present
            if(nums[lo]<=nums[mid])
                lo = mid+1;
            else
                hi = mid-1;
        }
        return nums[lo];
    }
};