class Solution {
public:
    bool util(int n, vector<int>& dp)
    {
        if(dp[n]!=-1) return dp[n]==1;
        
        bool res = false;
        
        for(int i = 1; i<=n/2; ++i)
        {
            if(res) break;
            if(n%i==0)
                res = !util(n-i, dp);
        }
        dp[n] = res?1:0;
        
        return res;
    }
    bool divisorGame(int n) {
        vector<int> dp(n+1, -1);
        return util(n,dp);
    }
};