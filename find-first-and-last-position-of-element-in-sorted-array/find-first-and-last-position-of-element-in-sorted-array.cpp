class Solution {
public:
    //the lower bound function finds the firstmost appearance of the element in the array from the starting.
    int lower_bound(vector<int>nums, int target)
    {
        int lo = 0, hi = nums.size()-1;
        
        while(lo<=hi)
        {
            int mid = lo+((hi-lo)>>1);
            if(nums[mid]<target) lo = mid+1;
            else hi = mid-1;
        }
        
        return lo;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        if(nums.size()==1) {
            if(nums[0]==target) return {0,0};
            else return {-1,-1};
        }

            
        //----------------------1st approach - 2 binary searches ------------//
        
        //Performing the first binary search for the starting index of the target element.
//         int lo = 0, hi = nums.size()-1;
//         int start = -1;
//         while(lo<hi)
//         {
//             int mid = lo+((hi-lo)>>1);
//             if(nums[mid]<target)
//                 lo = mid+1;
//             else
//                 hi = mid; 
//         }
        
//         start = lo;
        
//         if(nums[start]!=target) return {-1,-1};
        
//         int end = -1;
//         hi = nums.size()-1;
        
//         //Performing second binary search for finding last index of the element
//         while(lo<hi)
//         {
//             int mid = lo+((hi-lo)>>1) + 1;//slight modifiation here, we add 1 to mid because we always want mid to move forward and not stuck at the same place.
//             if(nums[mid]>target)
//                 hi = mid-1;
//             else
//                 lo = mid;
//         }
//         end = hi;
        
//         if(nums[end]!=target) return {-1,-1};
//         return {start,end};
        
        //-------------------------------end----------------//
        
        
        //--------------------2nd approach - lower bound method -----------------------//
        
        int start = lower_bound(nums,target);
        int end = lower_bound(nums,target+1) - 1; //searching for target+1 because even if target is present or not present, we will subtract 1 from the index of just greater element.
        
        if(start>=nums.size() || nums[start]!=target) return {-1,-1};
        
        return {start,end};
    }
};