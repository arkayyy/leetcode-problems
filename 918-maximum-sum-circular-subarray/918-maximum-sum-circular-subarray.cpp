class Solution {
public:
    
    //INTUITION: There can be two cases:
    //1. If the maximum sum subarray lies in the non-circular array
    //2. If the max sum subarray lies in the circular array...that means if we visualize the same array side by side...it would contain some last elements of the first half, and some starting elements of the second half...
    
    //In case 1 sum of the subarray can be found like in the general Kadane's algo
    //In case 2, max sum subarray = total sum of array - min sum subarray
    
    //EXPLANATION: https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/178422/One-Pass
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int currMax = 0, currMin =0;
        int max_so_far = nums[0], min_so_far = nums[0];
        
        for(int i = 0; i<nums.size();i++)
        {
            total+=nums[i];
            currMax = max(nums[i], currMax+nums[i]);
            max_so_far = max(max_so_far, currMax);
            currMin = min(nums[i], currMin+nums[i]);
            min_so_far = min(min_so_far, currMin);
        }
        
        
        
        return max_so_far>0?max(max_so_far, total-min_so_far):max_so_far;//max_so_far (max sum subarray) will be negative only when all elements of the array are negative..in that case the maximum element encountered will be stored in max_so_far
        
    }
};