class Solution {
public:
      //also try by expanding from middle method
    int expandFromMiddle(int l,int r, string s)
    {
        
        if(l>r || s=="")
            return 0;
        
        while(l>=0 && r<s.length() && s[l]==s[r])
        {
            l--;
            r++;
        }
        
        return r-l-1;
    }
    
    int util(int i, int j, string&s, vector<vector<int>>&dp)
    {
        if(i>=j) return 1;
        if(dp[i][j]!=-1) return dp[i][j]; //termination
        
        dp[i][j] = (s[i]==s[j])&&(util(i+1,j-1,s,dp));
        util(i+1,j,s,dp);
        util(i,j-1,s,dp);
        
        return dp[i][j];
    }
    
    string longestPalindrome(string s) {
        
        //DP Memoization Approach O
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        int maxLen = 1; string ans = s.substr(0,1);
        util(0,s.size()-1,s,dp);
        for(int i = 0; i<s.size(); ++i)
            for(int j = i+1; j<s.size(); ++j)
                if(dp[i][j] && j-i+1>maxLen)
                {
                    maxLen = j-i+1;
                    ans = s.substr(i,j-i+1);
                }
        return ans;
        
        
        //DP Approach O(N^2) Time O(N^2) Space
        // vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        // for(int i = 0; i<s.size(); ++i) dp[i][i] = 1;
        // int maxLen = 1; string ans = s.substr(0,1);
        // for(int i = s.size()-1; i>=0; --i) //since at every step, we are using the next row of dp matrix, so we have to move from n-1 to 0 in this loop
        //     for(int j = i+1; j<s.size(); ++j)
        //         if(s[i]==s[j] && (j-i==1 || dp[i+1][j-1]))
        //         {
        //             dp[i][j] = 1;
        //             if(j-i+1>maxLen){
        //                 maxLen = j-i+1;
        //                 ans = s.substr(i,j-i+1);
        //             }
        //         }
        // return ans;
        
         //Expand from middle approach O(N^2) Time O(1) Space:-
        
//         if(s=="" || s.length()<1)
//             return "";
        
        
//         int end = 0, start = 0;
        
//         for(int i=0;i<s.length();i++)
//         {
//             int len1 = expandFromMiddle(i,i,s);
//             int len2 = expandFromMiddle(i,i+1,s);
//             int len = max(len1,len2);
//             if(len>end-start)
//             {
//                 start = i-((len-1)/2);
//                 end = i+(len/2);
//             }
//         }
        
//         return s.substr(start, end-start+1);
        

    }
};