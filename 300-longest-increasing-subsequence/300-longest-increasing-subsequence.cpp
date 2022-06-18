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
        //Recursion + memoization:-
        
        //vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1,-1));
        // return util(0,-1,nums,dp);
        
        
        //TABULATION:-
        
//         vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1));
//         for(int prevIdx = 0; prevIdx<=nums.size();++prevIdx) dp[nums.size()][prevIdx] = 0;  //equivalent to base case of recursion
       
//         for(int i = nums.size()-1; i>=0; --i)
//             for(int prevIdx = nums.size()-1; prevIdx>=-1; --prevIdx)
//             {
//                 //NOTE: In dp array columns, all indexes are shifted by +1, because prevIdx is from -1(which is invalid index), it is made to start from 0 in dp array
//                 int res = dp[i+1][prevIdx+1]; //not take 
//                 if(prevIdx==-1 || nums[i]>nums[prevIdx])
//                     res = max(res, 1+dp[i+1][i+1]);//take
//                 dp[i][prevIdx+1] = res;
//             }
//         return dp[0][0];
        
        
        //BINARY SEARCH:-
        
        vector<int> curr;
        for(int i = 0; i<nums.size(); ++i)
        {
            if(curr.size()==0 || nums[i]>curr.back()) curr.push_back(nums[i]);
            else
            {
                auto it = lower_bound(curr.begin(),curr.end(),nums[i]);
                *it = nums[i];
            }
        }
        return curr.size();
        
    }
};