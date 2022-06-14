class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        while(lo<=hi)
        {
            int mid = lo+((hi-lo)>>1);
        
            if((mid-1<0 || nums[mid]>nums[mid-1]) && (mid+1>nums.size()-1 || nums[mid]>nums[mid+1])) return mid;//peak element found
            
            //otherwise going in the direction of the rising slope(by choosing the element which is greater than current)
            //there are 2 possibilities:-
            //a) rising slope has to keep rising till end of the array 
            //b) rising slope will encounter a lesser element and go down 
            if((mid-1<0 || nums[mid]>nums[mid-1]))
                lo = mid+1;
            else
                hi = mid-1;
        }
        return -1;
    }
};