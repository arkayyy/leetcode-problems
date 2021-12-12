class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(),nums.end(),0);
        
        if(target&1)
            return false;
        
        target >>= 1;
        
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(target+1, false));
        
        for(int i = 0;i<=nums.size();i++)
       {
           dp[i][0] = true;  //initialising...since, 0 sum(target) can be formed by elements upto any index (0 sum can be formed by all subsets of an array)
       }
        for(int i = 1;i<=nums.size();i++)
        {
            for(int j = 0; j<=target;j++)
            {
                if(dp[i-1][j])
                    dp[i][j] = true; // dp[i-1][j] denotes that if we don't use the element at ith index in the current sum, can a target sum of j be reached with the subset upto index i-1???!!
                else if(j>=nums[i-1])
                {
                    if(dp[i-1][j-nums[i-1]])
                        dp[i][j] = true;   //dp[i-1][j-nums[i-1]] denotes that if element at ith index of array is also included, then can the remaining balance sum of (j-nums[i-1]) be acquired by the subset upto index (i-1) ??!
                }
                
            }
        }
        
        return dp[nums.size()][target];
    }
};