class Solution {
public:
    int findMin(vector<int>& nums) {
        //Using brute-force linear search technique:-
         
//         for(int i = 0;i<nums.size()-1;i++)
//         {
//             if(nums[i]>nums[i+1])
//             {
                
//                 return nums[i+1];
//             }
//         }
        
//         return nums[0];
        
        
        //Using OPTIMAL Binary Search technique:-
        
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return min(nums[0],nums[1]);
        
        int lo = 0, hi = nums.size()-1;
        int mini = INT_MAX;
        while(lo<=hi)
        {
            int mid = lo+((hi-lo)/2);
            
            if(lo==mid) //base case for terminating binary search
                break;

            if(nums[mid]>nums[hi])
               { lo = mid+1;
               mini = min(nums[hi],nums[lo]);}
            else
                {hi=mid; mini = min(nums[hi],nums[lo]);}
        }
        
        return mini;
    }
};