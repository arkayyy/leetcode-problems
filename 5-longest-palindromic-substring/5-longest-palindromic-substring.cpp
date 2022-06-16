class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        for(int i = 0; i<s.size(); ++i) dp[i][i] = 1;
        int maxLen = 1; string ans = s.substr(0,1);
        for(int i = s.size()-1; i>=0; --i)
            for(int j = i+1; j<s.size(); ++j)
                if(s[i]==s[j] && (j-i==1 || dp[i+1][j-1]))
                {
                    dp[i][j] = 1;
                    if(j-i+1>maxLen){
                        maxLen = j-i+1;
                        ans = s.substr(i,j-i+1);
                    }
                }
        return ans;
    }
};