class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(p.size()+1,vector<int> (s.size()+1,0));
        dp[0][0] = 1;
        for(int i = 1; i<=p.size(); ++i)
            for(int j = 0; j<=s.size(); ++j)
            {
                if(j==0) {if(p[i-1]=='*')dp[i][j] = dp[i-2][j];}
                else if(p[i-1]==s[j-1] || p[i-1]=='.') dp[i][j] = dp[i-1][j-1];
                else if(p[i-1]=='*') {dp[i][j] = dp[i-2][j]; if(p[i-2]==s[j-1] || p[i-2]=='.') dp[i][j] = dp[i][j] || dp[i][j-1];}
            }
        return dp[p.size()][s.size()];
    }
};