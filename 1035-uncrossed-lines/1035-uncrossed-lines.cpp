class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        //Finding LCS (with slight variation in the base case as below):-
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        //0th row and 0th column are filled zero indicating that with no characters from one array there's impossible to form even a single line with any element of the other array
        for(int i = 1;i<=n; ++i)
            for(int j = 1; j<=m; ++j)
                if(nums1[i-1]==nums2[j-1]) dp[i][j] = dp[i-1][j-1]+1; //if numbers are equal it adds p   
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        
        return dp[n][m];
    }
};