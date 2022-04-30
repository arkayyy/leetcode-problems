class Solution {
public:
    bool util(int i, int j, string& pattern, string& text, vector<vector<int>>& dp)
    {
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i>=0)
        {
            for(int k=i; k>=0; k--)
                if(pattern[k]!='*') return false;
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(pattern[i]==text[j] || pattern[i]=='?') return dp[i][j] = util(i-1,j-1,pattern,text,dp);
        
        if(pattern[i]=='*')
            return dp[i][j] = util(i-1,j,pattern,text,dp) + util(i,j-1,pattern,text,dp);
        
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = p.size(); //pattern
        int m = s.size(); //text
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return util(n-1,m-1,p,s,dp);
    }
};