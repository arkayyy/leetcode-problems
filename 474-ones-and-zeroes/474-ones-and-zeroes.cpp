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
        
        memset(dp,-1,sizeof(dp));
        vector<int> ones(strs.size()), zeros(strs.size());
        for(int i = 0; i<strs.size(); ++i)
        {
            int z = 0, o = 0;
            for(auto c: strs[i]) {if(c=='0') ++z; else ++o;}
            zeros[i] = z, ones[i] = o;
        }
        return util(strs.size()-1, m, n, ones, zeros);
        
        
    }
};