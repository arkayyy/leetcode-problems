class Solution {
public:
    //INTUITION: Marking all view points of every guard, and at last checking for unguarded spaces
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        for(auto g: guards)
            grid[g[0]][g[1]] = 1;
        for(auto w: walls)
            grid[w[0]][w[1]] = 2;
        
        for(auto g: guards)
        {
            int r = g[0], c = g[1];
            for(int i = r-1; i>=0 && grid[i][c]!=1 && grid[i][c]!=2 ; i--)
            {
                grid[i][c] = 5;
            }
            for(int i = r+1; i<m && grid[i][c]!=1 && grid[i][c]!=2; i++)
            {
                grid[i][c] = 5;
            }
            for(int j = c-1; j>=0 && grid[r][j]!=1 && grid[r][j]!=2 ; j--)
            {
                grid[r][j] = 5;
            }
            for(int j = c+1; j<n && grid[r][j]!=1 && grid[r][j]!=2 ; j++)
            {
                grid[r][j] = 5;
            }
        }
        int cnt = 0;
        for(int i = 0; i<m; i++)
            for(int j = 0; j<n; j++)
                if(grid[i][j]==0)
                    cnt++;
        
        return cnt;
    }
};