class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        
        int n = nums.size();
        
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        if(n==3) return max(nums[0]+nums[2],nums[1]);
        
        dp[n-1] = nums[n-1];
        dp[n-2] = nums[n-2];
        dp[n-3] = nums[n-1]+nums[n-3];
        
        for(int i = nums.size()-4;i>=0;i--)
        {
            dp[i] = nums[i]+max(dp[i+2],dp[i+3]);
           
        }
        
        return max(dp[0],dp[1]);
        
        
    }
};