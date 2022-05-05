class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        bool allZeros = true;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        for(int i = 0; i<matrix.size(); i++) { if(matrix[i][0]=='1') {allZeros = false; dp[i][0] = 1;} else dp[i][0] = 0; }
        for(int j = 0; j<matrix[0].size(); j++) {if(matrix[0][j]=='1') {allZeros = false; dp[0][j] = 1;} else dp[0][j] = 0; }
        
        int ans = 1; 
        for(int i = 1; i<matrix.size(); i++)
            for(int j = 1; j<matrix[0].size(); j++)
                if(matrix[i][j]=='1')
                    { allZeros = false; ans = max(ans, dp[i][j] = 1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) );}
        
        return allZeros?0:(ans*ans);

        //Space optimized DP:-
//         vector<vector<int>> dp(2, vector<int>(matrix[0].size())); //taking two rows, 0th for the previous row and 1st for the current
//         for(int i = 0; i<matrix.size(); i++) if(matrix[i][0]=='1') allZeros = false; //to handle the edge case of only one column in matrix
        
//         for(int j = 0; j<matrix[0].size(); j++) {if(matrix[0][j]=='1') {allZeros = false; dp[0][j] = 1;} else dp[0][j] = 0; } //initializing DP array
        
//         if(matrix.size()>1) dp[1][0] = matrix[1][0]=='1'?1:0;
        
//         int ans = 1; 
//         for(int i = 1; i<matrix.size(); i++)
//           {  for(int j = 1; j<matrix[0].size(); j++)
//                { 
//                 if(matrix[i][j]=='1')
//                     { allZeros = false; ans = max(ans, dp[1][j] = 1+min({dp[0][j], dp[1][j-1], dp[0][j-1]}) );}
               
//             }
//            dp[0] = dp[1];
//         }
//         return allZeros?0:(ans*ans);
        
    }
};