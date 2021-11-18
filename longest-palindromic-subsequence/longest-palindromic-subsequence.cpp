class Solution {
public:
    int longestPalindromicSubseq(int i, int j, string &s,vector<vector<int>> & dp)
    {
        if(i>j)
            return 0;
        if(i==j)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==s[j])
            return dp[i][j] = (2+longestPalindromicSubseq(i+1,j-1,s,dp));
        
        return dp[i][j] = (max(longestPalindromicSubseq(i+1,j,s,dp), longestPalindromicSubseq(i,j-1,s,dp)));
    }
    int longestPalindromeSubseq(string s) {
        
        vector<vector<int>> dp(s.length(), vector<int> (s.length(),-1));
        return longestPalindromicSubseq(0,s.length()-1,s,dp);
        
        
    }
};