class Solution {
public:
    int countHousePlacements(int n) {
        int mod = 1e9+7;
        //Placement of houses on one side doesn't affect the placement on the other side.
        //So we will find total numnber of ways to fill n plots on one side, and square it to get total no. of combinations including the other side too
        vector<long long> dp(n+1,0);
        dp[0] =1, dp[1] =2;
        for(int i = 2; i<=n;++i)
            dp[i] = (dp[i-1]+dp[i-2])%mod;
        return ((long long)dp[n]*(long long)dp[n])%mod;
    }
};