class Solution {
public:
    int util(int i, int prevIdx, vector<int>&nums, vector<vector<int>>& dp)
    {
        if(i==nums.size()) return 0;
        if(dp[i][prevIdx+1]!=-1) return dp[i][prevIdx+1];
        int res = 0;
        if(prevIdx==-1 || nums[i]>nums[prevIdx]) res = 1+util(i+1,i,nums,dp);
        
        res = max(res, util(i+1,prevIdx,nums,dp));
        
        return dp[i][prevIdx+1]=res;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1,-1));
        return util(0,-1,nums,dp);
    }
};