class Solution {
public:
    int util(int i, int n, vector<char> &vowels, int&ans, vector<vector<int>>& dp)
    {
        if(n==0) {++ans; return 1;}
        
        int res = 0;
        for(int j = i; j<vowels.size(); j++)
            res += util(j,n-1, vowels,ans,dp);
        
        return dp[n][i] = res;
    }
    int countVowelStrings(int n) {
        vector<char> vowels = {'a','e','i','o','u'};
        int ans = 0;
        vector<vector<int>> dp(n+1, vector<int> (5));
        return util(0,n,vowels,ans, dp);
        //return ans;
    }
};