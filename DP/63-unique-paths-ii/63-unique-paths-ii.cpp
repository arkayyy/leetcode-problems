class Solution {
public:
    int util(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
    {
        if(i==obstacleGrid.size()-1 && j==obstacleGrid[0].size()-1) return 1; //if destination reached
        
        int steps = 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        //moving down
        if(i+1 < obstacleGrid.size() && !visited[i+1][j] && obstacleGrid[i+1][j]!=1)
        {
            visited[i+1][j] = true;
            steps+= util(i+1,j,visited,obstacleGrid,dp);
            visited[i+1][j] = false; //backtracking step
        }
        //moving right
        if(j+1 < obstacleGrid[0].size() && !visited[i][j+1] && obstacleGrid[i][j+1]!=1)
        {
            visited[i][j+1] = true;
            steps+= util(i,j+1,visited,obstacleGrid,dp);
            visited[i][j+1] = false; //backtracking step
        }
        
        return dp[i][j] = steps;
        

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
       vector<vector<bool>> visited(obstacleGrid.size(),vector<bool>(obstacleGrid[0].size(),false));
        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        visited[0][0] = true;
        
        return util(0,0,visited,obstacleGrid,dp);
    }
};