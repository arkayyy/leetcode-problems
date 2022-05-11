class Solution {
public://Top down: i-> 0 to 5 AND n->n to 0
    int util(int i, int n, vector<char> &vowels, vector<vector<int>>& dp)
    {
        if(n==0) {return 1;} //base case
        
        int res = 0;
        for(int j = i; j<vowels.size(); j++)
            res += util(j,n-1, vowels,dp);
        
        return dp[n][i] = res;
    }
    int countVowelStrings(int n) {
        
        vector<char> vowels = {'a','e','i','o','u'};
        //====================APPROACH 1: Recursion+Memoization O(5*N) Time O(5*N)+O(N) aux space========================// 
        // vector<vector<int>> dp(n+1, vector<int> (5));
        // return util(0,n,vowels, dp);
        
        //====================APPROACH 2: Space Optimized Tabulation DP O(5*N) Time O(1) Space ==============================//
//         vector<int> dp(5,1);
//         dp[0] = 1; // similar to base case in recursion
//         for(int i = 0; i<n; i++)
//             for(int j = 1; j<vowels.size(); j++)
//                 dp[j]+=dp[j-1];
//         return dp[4];
        
        //====================APPROACH 3: Combinations O(1) Time O(1) Space===================================//
        //Formula for total no. of combinations with repititions = nCk = (n+k-1)!/(n! * (k-1)!)
        //Here, k = 5 vowels, the formula will become = nC5 = (n+4)!/(5!*(n-1)!) = (n+1)*(n+2)*(n+3)*(n+4) / 4!
        return (n+1)*(n+2)*(n+3)*(n+4)/24;
    }
};