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
        
        //=================================APPROACH 1: Recursion+Memo O(N) Time O(N)+O(N)aux space===========================//
        // vector<int> dp(nums.size(), -1);
        // int zero = util(0,nums.size()-1, nums,dp); //rob houses from 0th index to n-2th (2nd last index) ...here n-1 is just the limit for terminating recursion
        // fill(dp.begin(),dp.end(),-1);
        // int one = util(1,nums.size(),nums,dp);//from 1st index to n-1th(last) index.here n is just the limit for terminating recursion
        // return max(zero,one);
        
        
        //==================================APPROACH 2: Tabulation DP(Bottom up) O(N) Time O(N) Space===========================//:-
//         vector<int> dp(nums.size()+1);
//         dp[nums.size()] = 0;
//         dp[nums.size()-1] = nums.back();
//         for(int i = nums.size()-2; i>=1; i--)
//             dp[i] = max(nums[i]+dp[i+2], dp[i+1]);
//         int ans = dp[1];
        
//         dp[nums.size()-1] = 0;
//         dp[nums.size()-2] = nums[nums.size()-2];
//         for(int i = nums.size()-3; i>=0; i--)
//             dp[i] = max(nums[i]+dp[i+2], dp[i+1]);
        
//         return max(ans,dp[0]);
        
        //==============================APPROACH 3: Space optimized DP O(N) Time O(1) Space===================================//:-
        int skipNext = 0, dontSkipNext = nums.back(),curr;
        for(int i = nums.size()-2; i>=1; i--)
            {curr = max(nums[i]+skipNext, dontSkipNext); skipNext = dontSkipNext; dontSkipNext = curr;}
        int ans = curr;
        
        skipNext = 0, dontSkipNext = nums[nums.size()-2];
        for(int i = nums.size()-3; i>=0; i--)
            {curr = max(nums[i]+skipNext, dontSkipNext); skipNext = dontSkipNext; dontSkipNext = curr;}
        return max(ans,curr);
    }
};