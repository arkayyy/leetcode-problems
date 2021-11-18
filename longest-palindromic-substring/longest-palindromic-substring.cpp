class Solution {
public:
    //also try by 
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(),-1));
        int l = 0, r = 0;
        for(int i = 0; i<s.length() ;i++)
        {
            for(int j = 0, k = i; k<s.length();j++,k++)
            {
                if(i==0)
                    dp[j][k] = 1;
                else if(i==1)
                    dp[j][k] = (s[j]==s[k])?1:0;
                else if(s[j]==s[k] && dp[j+1][k-1])
                    dp[j][k] = true;
                else
                    dp[j][k] = false;
                
                if(dp[j][k])
                {l = j; r = k;}
            }
        }
        
        return s.substr(l,r-l+1);
        
    }
};