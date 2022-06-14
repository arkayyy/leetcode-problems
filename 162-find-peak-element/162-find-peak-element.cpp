class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        while(lo<=hi)
        {
            int mid = lo+((hi-lo)>>1);
            if((mid-1<0 || nums[mid]>nums[mid-1]) && (mid+1>nums.size()-1 || nums[mid]>nums[mid+1])) return mid;
            if((mid-1<0 || nums[mid]>nums[mid-1]))
                lo = mid+1;
            else
                hi = mid-1;
        }
        return -1;
    }
};