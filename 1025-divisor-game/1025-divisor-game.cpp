class Solution {
public:
    //Function for Recursion + Memoization :-
    bool util(int n, vector<int>& dp)
    {
        if(dp[n]!=-1) return dp[n]==1;
        
        bool res = false;
        
        for(int i = 1; i<=n/2; ++i)
        {
            if(res) break;
            if(n%i==0)
                res = !util(n-i, dp);
        }
        dp[n] = res?1:0;
        
        return res;
    }
    bool divisorGame(int n) {
        //========================APPROACH 1: Recursion + Memoization DP TC:O(N^2) SC:O(N) extra aux space========================================//
        vector<int> dp(n+1, 0);
        // return util(n,dp);
        
        //========================APPROACH 2: Tabulation DP TC:O(N^2) SC:O(N)===========================================//
//         dp[0] = 0;
//         dp[1] = 0;
//         for(int i = 2; i<=n; ++i)
//             for(int j = 1; j<=i/2; ++j)
//                 if(i%j==0)
//                     dp[i] = dp[i] || !dp[i-j];
//         return dp[n];
        
        //=======================APPROACH 3: Mathematics TC:O(1) SC:O(1) ===============================//
        return n%2==0; //because if n is even, alice can decrement 1 from it to convert the no. left for Bob's chance to be odd
        //Now since odd number can only have odd factors. SO whatever factor bob selects will be odd.
        //Now (odd - odd) = even no. SO alice will be getting an even number for his chance no matter what, and he repeatedly keeps
        //converting that even number to odd. So that at last bob is left with 1. (SO HE LOSES!) 
    }
};