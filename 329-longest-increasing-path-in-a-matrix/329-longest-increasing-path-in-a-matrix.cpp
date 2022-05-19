class Solution {
public:
    //INTUITION & ALGO: Simple Recursion with Memoization!
    int util(vector<vector<int>>& mat, int i, int j, int prev, vector<vector<int>>& dp){
        if(i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || mat[i][j] <= prev) return 0;
        if(dp[i][j]) return dp[i][j];
        return dp[i][j] = 1 + max({ util(mat, i + 1, j, mat[i][j], dp),
                                    util(mat, i - 1, j, mat[i][j], dp),
                                    util(mat, i, j + 1, mat[i][j], dp),
                                    util(mat, i, j - 1, mat[i][j], dp) });       
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0, n =matrix.size(), m =matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                ans = max(ans, util(matrix, i, j, -1,dp));            
        return ans;
    }

};