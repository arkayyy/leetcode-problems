class Solution {
public:
    //-----------------------------------INTUITION-------------------------------------------//
    //STEP 1:
    //This is an implementation of the problem: count subsets with a given difference (explained by Aditya Verma in his DP playlist)
    //Here in place of difference, we take this given target sum itself 
    //This is because if we take positive sign for some elements of the array and negative sign for the others, 
    //it'll be like sumOf(Subset 1 with all positive signs with elems)+sumOf(Subset 2 with all negative signs with elements)
    //This can also be alternatively written as: sumOf(Subset 1 with all positive signs with elems) - sumOf(subset 2 with all positive signs with elements). So it boils down to: count subsets with given difference
    
    //STEP 2:
    //Now again count subsets with given difference can also be alternated as count subsets with sum=(diff+totalofallelemsinArray)/2 (ADITYA VERMA DP PLAYLIST) 
    
    int countSubsetsWithSum(int sum, vector<int>& nums)
    {
        
        vector<vector<int>> dp(nums.size()+1, vector<int>(sum+1,0));
        for(int i=0; i<=nums.size(); i++)
            dp[i][0] = 1;
        
        for(int i = 1; i<=nums.size(); i++)
        {
            for(int j = 0; j<=sum; j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j>=nums[i-1])
                    dp[i][j] += dp[i-1][j-nums[i-1]];
            }
        }
        
        return dp[nums.size()][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int difference = abs(target);
        int total = accumulate(nums.begin(),nums.end(),0);
        
        if((total+(difference))%2!=0) return 0;
        int targ = ((total+(difference))>>1);
        if(targ>total || target>total ) return 0;
        return countSubsetsWithSum(targ,nums); 
    }
};