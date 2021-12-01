class Solution {
public:
    int rob(vector<int>& nums) {
        
// This problem can simply be decomposed into two House Robber problems.
// Suppose there are n houses, since house 0 and n - 1 are now neighbors, we cannot rob them together and thus the solution is now the maximum of:-

// 1. Rob houses 0 to n - 2;
// 2. Rob houses 1 to n - 1.
        
        //Some edge cases (n < 2) are handled explicitly.
        if(nums.size()==1) return nums[0];
        
        if(nums.size()==2) return max(nums[0],nums[1]);
      
        return max(robber(nums,0,nums.size()-2),robber(nums,1,nums.size()-1));
    }
    
    int robber(vector<int>&nums, int i, int j)
    {
        int pre = 0, cur = 0; 
        for(int k = i; k <= j; k++)
        {
            if(k&1) pre = max(pre+nums[k], cur);
            else cur = max(pre, cur+nums[k]);
        }
        
        return max(pre,cur);
    }
};