class Solution {
public:
    bool util(int i, int j, string& pattern, string& text, vector<vector<int>>& dp)
    {
        if(i<0 && j<0) return true; //base case 1
        if(i<0 && j>=0) return false;//base case 2
        if(j<0 && i>=0)//base case 3
        {
            for(int k=i; k>=0; k--)
                if(pattern[k]!='*') return false;
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(pattern[i]==text[j] || pattern[i]=='?') return dp[i][j] = util(i-1,j-1,pattern,text,dp); //recurrence 1
        
        if(pattern[i]=='*')
            return dp[i][j] = util(i-1,j,pattern,text,dp) + util(i,j-1,pattern,text,dp); //recurrence 2
        
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = p.size(); //pattern
        int m = s.size(); //text
        
        //============================Approach 1: Recursion+Memoization==================//
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return util(n-1,m-1,p,s,dp);
        
        //=============================Approach 2: Tabulation DP==========================//
        //vector<vector<bool>> tdp(n+1,vector<bool>(m+1,false));
        //Base cases:-
//         tdp[0][0] = true; //Base case 1
//         for(int j = 1; j<=m; j++) tdp[0][j] = false; //Base case 2
//         for(int i = 1; i<=n; i++) //Base case 3
//         {
//             bool flag = true;
//             for(int k = i; k>=1; k--)
//                 if(p[k-1]!='*') {flag = false; break;}
//             tdp[i][0] = flag;
//         }
        
//         for(int i = 1; i<=n; i++)
//         {
//             for(int j = 1; j<=m; j++)
//             {
//                 //Recurrence relations:-
//                 if(p[i-1]==s[j-1] || p[i-1]=='?') 
//                     tdp[i][j] = tdp[i-1][j-1];//Recurrence 1
//                 else if(p[i-1]=='*')
//                     tdp[i][j] = tdp[i-1][j] || tdp[i][j-1]; //Recurrence 2
//                 else 
//                     tdp[i][j] = false; 
//             }
//         }
        
//         return tdp[n][m];
        
        //===================Approach 3: Tabulation Space Optimization=====================//
        vector<bool> prev(m+1,false);
        vector<bool> curr(m+1,false);
        prev[0] = true; //Base case 1
        for(int j = 1; j<=m; j++)//Base case 2
            prev[j] = false; 
        for(int i = 1; i<=n; i++)
        {
            //Base case 3:-
            bool flag = true;
            for(int k=i; k>=1; k--)
                if(p[k-1]!='*') {flag = false; break;}
            curr[0] = flag;
            
            //Recurrence relations:-
            for(int j = 1; j<=m; j++)
            {
                if(p[i-1]==s[j-1] || p[i-1]=='?') 
                    curr[j] = prev[j-1];//Recurrence 1
                else if(p[i-1]=='*')
                    curr[j] = prev[j] || curr[j-1]; //Recurrence 2
                else 
                    curr[j] = false; 
            }
            prev = curr;
        }
        return prev[m];
    }
};