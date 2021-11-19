class Solution {
public:
    //BRUTE FORCE - Recursion - TLE:-
    bool util(int curr, int i, vector<int>& nums, int sum)
    {
        if(i>=nums.size() || curr>sum )
            return false;
        if(curr==sum)
            return true;
        
        return util(curr+nums[i], i+1, nums, sum)||util(curr,i+1,nums,sum);
    }
    bool canPartition(vector<int>& nums) {
       int sum = 0;
        for(auto i:nums)
            sum+=i;
        
        if((sum&1)==1)
            return false;  //if sum is not even, it can be partitioned into two halves
        sum = (sum>>1);
        
//         return util(0,0,nums,sum);
        
        
        
        //OPTIMAL APPROACH - Tabular DP (Bottoms Up) (For reference watch: https://www.youtube.com/watch?v=tRpkluGqINc) :-
        
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(sum+1,false)); // row number denotes index of element in array and goes upto (size of array+1). It basically denotes that upto which index in the array we are considering.
        //column number denotes the sum(target) and goes upto (required sum+1)
        
       for(int i = 0;i<=nums.size();i++)
       {
           dp[i][0] = true;  //initialising...since, 0 sum(target) can be formed by elements upto any index (0 sum can be formed by all subsets of an array)
       }
        for(int i = 1;i<=nums.size();i++)
        {
            for(int j = 0; j<=sum;j++)
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
        
        return dp[nums.size()][sum]; // dp[nums.size()][sum] denotes that whether a target sum of (sum) be acquired by the subset of the array upto last index
        
    }
};