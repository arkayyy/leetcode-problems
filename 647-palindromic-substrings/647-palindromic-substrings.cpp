class Solution {
    //INTUITION: The substring b/w indexes i and j can be a valid palindrome only when:
    //(i) s[i]==s[j] 
    //(ii) and the substring b/w i+1 and j-1 is also a valid palindrome
    
public:
    //Recursion + memoization fn:-
    int checkPalindrome(string& s, int i, int j, vector<vector<int>>& dp)
    {
        if(i>=j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = s[i]==s[j]?checkPalindrome(s,i+1,j-1, dp):0;
    }
    int countSubstrings(string s) {
        //==============================APPROACH 1: Recursion + Memoization O(N^2) Time O(N^2) + recusrion aux Space============================//
        // vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1)); //dp[i][j] = 1 or 0, denotes whether the substring in between i and j indices is plaindromic or not
        // int ans = 0;
        // for(int i = 0; i<s.size(); ++i)
        //     for(int j = i; j<s.size(); ++j)
        //         ans += checkPalindrome(s, i, j, dp);
        // return ans;
        
        
        //===============================APPROACH 2: Tabulation DP O(N^2) Time O(N^2) Space (no recursion aux space)===========================//
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