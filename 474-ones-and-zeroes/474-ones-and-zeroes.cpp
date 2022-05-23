class Solution {
public:
    int dp[601][101][101]; //memoizing using arrays is faster since memory is allocated statically here
    int util(int i, int m, int n, vector<int>&ones, vector<int>&zeros, int one, int zero)
    {
        if(i<0 || zero>m || one>n) return 0;
        if(dp[i][zero][one]!=-1) return dp[i][zero][one];
        
        if(zero+zeros[i]<=m && one+ones[i]<=n)
            return dp[i][zero][one] = max(1+util(i-1, m, n, ones, zeros, one+ones[i], zero+zeros[i]) ,  util(i-1,m,n,ones, zeros, one, zero));
        
        return dp[i][zero][one] = util(i-1,m,n,ones, zeros, one, zero);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        //vector<vector<vector<int>>> dp(600, vector<vector<int>> (100, vector<int>(100,-1))); -> NOTE: using vector for memoizing gives TLE here.
        memset(dp,-1,sizeof(dp));
        vector<int> ones(strs.size()), zeros(strs.size());
        for(int i = 0; i<strs.size(); ++i)
        {
            int z = 0, o = 0;
            for(auto c: strs[i]) {if(c=='0') ++z; else ++o;}
            zeros[i] = z, ones[i] = o;
        }
        return util(strs.size()-1, m, n, ones, zeros, 0, 0);
    }
};