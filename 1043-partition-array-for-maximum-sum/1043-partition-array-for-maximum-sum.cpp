class Solution {
public:
    int util(int i, vector<int>& arr, int k, vector<int>&dp)
    {
        if(i==arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi = 0, maxSum = 0;
        for(int j = 0; j<k; ++j)
        {
            if(i+j>=arr.size()) break;
            maxi = max(maxi,arr[i+j]);
            maxSum = max(maxSum, maxi*(j+1) + util(i+j+1,arr,k,dp));
        }
        return dp[i] = maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return util(0,arr,k,dp);
    }
};