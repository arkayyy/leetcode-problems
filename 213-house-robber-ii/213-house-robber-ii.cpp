class Solution {
public:
    int util(int i, int n, vector<int> &nums, vector<int>&dp)
    {
        if(i>=n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int take = nums[i]+util(i+2,n,nums,dp);
        int dontTake = util(i+1, n, nums,dp);
        
        return dp[i]=max(take,dontTake);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1 || nums.size()==2) return *max_element(nums.begin(),nums.end());
        vector<int> dp(nums.size(), -1);
        int zero = util(0,nums.size()-1, nums,dp);
        fill(dp.begin(),dp.end(),-1);
        int one = util(1,nums.size(),nums,dp);
        return max(zero,one);
    }
};