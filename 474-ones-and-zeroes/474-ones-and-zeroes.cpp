class Solution {
public:
    int dp[601][101][101]; //memoizing using arrays is faster since memory is allocated statically here
    int util(int i, int m, int n, vector<int>&ones, vector<int>&zeros)
    {
        if(i<0 || m<0 || n<0) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        
        if(m-zeros[i]>=0 && n-ones[i]>=0)
            return dp[i][m][n] = max(1+util(i-1, m-zeros[i], n-ones[i], ones, zeros) ,  util(i-1,m,n,ones, zeros));
        
        return dp[i][m][n] = util(i-1,m,n,ones, zeros);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        // memset(dp,-1,sizeof(dp));
        vector<int> ones(strs.size()), zeros(strs.size());
        for(int i = 0; i<strs.size(); ++i)
        {
            int z = 0, o = 0;
            for(auto c: strs[i]) {if(c=='0') ++z; else ++o;}
            zeros[i] = z, ones[i] = o;
        }
        // return util(strs.size()-1, m, n, ones, zeros);
        
        
        //Tabulation DP:-
        memset(dp,0,sizeof(dp)); //base case (just for visualising, actual variable names may be taken differently): 
        //whenever i==0 || m==0 || n==0 then dp[i][m][n] = 0. So by default setting all as 0.
        for(int i = 1; i<=strs.size(); ++i)
            for(int j = 0; j<=m; ++j)
                for(int k = 0; k<=n; ++k)
                {
                    dp[i][j][k] = dp[i-1][j][k];
                    if(j-zeros[i-1]>=0 && k-ones[i-1]>=0)
                        dp[i][j][k] = max(1+dp[i-1][j-zeros[i-1]][k-ones[i-1]], dp[i-1][j][k]);
                }
        return dp[strs.size()][m][n];
    }
};