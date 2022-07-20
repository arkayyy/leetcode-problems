class Solution {
public:
    bool subsetSum(vector<int>& nums, int target)
    {
        vector<vector<int>>dp(nums.size()+1, vector<int>(target+1,0));
        for(int i = 1; i<=nums.size(); ++i)
            for(int j = 0; j<=target; ++j)
            {
                
                if(j==0) dp[i][j] = 1;
                else {
                    dp[i][j] =dp[i-1][j];
                    if(nums[i-1]<=j)
                        dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
                }
            }
        return dp[nums.size()][target];
    }
    bool canPartition(vector<int>& nums) {
        long long sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return false;
        return subsetSum(nums,sum/2);
    }
};