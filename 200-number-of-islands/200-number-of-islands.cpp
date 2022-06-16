class Solution {
public:
   
    void dfs(int i,  int j, vector<vector<char>>&grid, vector<vector<int>>& visited)
    {
        visited[i][j] = 1;
        if(i+1<grid.size() && grid[i+1][j]=='1' && !visited[(i+1)][j]) dfs(i+1,j,grid,visited);
        if(i-1>=0 && grid[i-1][j]=='1' && !visited[(i-1)][j]) dfs(i-1,j,grid,visited);
        if(j+1<grid[0].size() && grid[i][j+1]=='1' && !visited[(i)][j+1]) dfs(i,j+1,grid,visited);
        if(j-1>=0 && grid[i][j-1]=='1' && !visited[(i)][j-1]) dfs(i,j-1,grid,visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int cnt = 0;
        for(int i = 0; i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j)
                if(grid[i][j]=='1' && !visited[i][j])
                    ++cnt,dfs(i,j,grid,visited);
        return cnt;
    }
};