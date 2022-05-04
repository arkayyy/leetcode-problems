class Solution {
    //INTUITION: This is a slight modification of the House Robber 1. The only extra condition in part II is that we can't rob the first index and last index house together in any condition, because they are adjacent.
    //Rest all the thought process is same as that of House Robber Part I.
    
    //ALGO: So we can either rob houses from 0th index to n-2th (2nd last index) OR from 1st index to n-1th(last) index. Max between both is our answer.
public:
    //Recursion + Memoization (Top Down) -> Going from left to right and memoizing. So in bottom up/tabulation we will go in opposite direction!
    int util(int i, int n, vector<int> &nums, vector<int>&dp)
    {
        if(i>=n) return 0;
        
        if(dp[i]!=-1) return dp[i]; //if already found as memoized
        
        int take = nums[i]+util(i+2,n,nums,dp); //taking current house means can't take next/i+1th index house
        int dontTake = util(i+1, n, nums,dp); //can take i+1th house if current house not robbed
        
        return dp[i]=max(take,dontTake);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1 || nums.size()==2) return *max_element(nums.begin(),nums.end());
        vector<int> dp(nums.size(), -1);
        int zero = util(0,nums.size()-1, nums,dp); //rob houses from 0th index to n-2th (2nd last index) ...here n-1 is just the limit for terminating recursion
        fill(dp.begin(),dp.end(),-1);
        int one = util(1,nums.size(),nums,dp);//from 1st index to n-1th(last) index.here n is just the limit for terminating recursion
        return max(zero,one);
    }
};