class Solution {
    //INTUTION: The different combinations of the same number button would be caused by various no. of repititions of itself being considered.
    //So whenever we find any repititions of the same number, we assess the different possibilities of the character being added.
public:
    int MOD = 1e9 + 7;
    int util(int i, string s, int n, vector<int>&dp)
    {
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i]%MOD;
        int cnt = 0;
        if(i+3<n && (s[i]=='7'||s[i]=='9') && s[i]==s[i+1]&&s[i+1]==s[i+2] && s[i+2]==s[i+3]) cnt=(cnt%MOD+util(i+4,s,n,dp)%MOD)%MOD;
        if(i+2<n && s[i]==s[i+1] && s[i+1]==s[i+2]) cnt=(cnt%MOD+ util(i+3,s,n,dp)%MOD)%MOD;
        if(i+1<n && s[i]==s[i+1]) cnt= (cnt%MOD + util(i+2,s,n,dp)%MOD)%MOD;
        cnt= (cnt%MOD + util(i+1,s,n,dp)%MOD)%MOD;
        
        return dp[i]=cnt%MOD;
    }
    int countTexts(string s) {
        //=================APPROACH 1: Memoization O(N) Time & O(N)+Recursion Aux Space (Gives memory limit exceeded error)====================================//
        //vector<int> dp(s.size(),-1);
        //return util(0,s,s.size(),dp)%MOD;
        
        
        //==============APPROACH 2: Tabulation DP O(N) Time O(N) Space ==================================//
        vector<int> dp(s.size()+1,0);
        dp[0] = 1;
        for(int i = 1; i<=s.size(); ++i)
        {
            dp[i] =( dp[i]+dp[i-1])%MOD;
            if(i-2>=0 && s[i-1]==s[i-2]) {
                dp[i] = (dp[i]+dp[i-2])%MOD;
                if(i-3>=0 && s[i-1]==s[i-3])
                {
                    dp[i] = (dp[i] + dp[i-3])%MOD;
                    if(i-4>=0 && (s[i-1]=='7'||s[i-1]=='9') && s[i-1]==s[i-4])
                        dp[i] = (dp[i]+dp[i-4])%MOD;
                }
            }
        }
        return dp.back();
    }
};