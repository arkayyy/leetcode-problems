class Solution {
public:

    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size())); //dp[i][j] = 1 or 0, denotes whether the substring in between i and j indices is plaindromic or not
        int ans = 0;
        for(int i = s.size()-1; i>=0; --i)
            for(int j = i; j<s.size(); ++j)
            {
                if(i==j) dp[i][j] = 1;
                else if(i+1==j) dp[i][j]  = s[i]==s[j]?1:0;
                else dp[i][j] = s[i]==s[j]?dp[i+1][j-1]:0;
                ans+=dp[i][j];
            }
        return ans;
    }
};