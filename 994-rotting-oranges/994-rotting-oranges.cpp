class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //ALGO: Mutli-Source BFS
        queue<vector<int>> bfs; //{row,col,mins}
        int noOfMinutes = 0;
        int countNotEmpty = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols,false));
        
        for(int i = 0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==0)
                    visited[i][j] = true;
                if(grid[i][j]==2)
                    { bfs.push({i,j,0}); visited[i][j] = true; }
            }
        }
        
        while(!bfs.empty())
        {
            vector<int> elem = bfs.front();
            bfs.pop();
            int r = elem[0], c = elem[1], mins = elem[2];
            
            noOfMinutes = max(noOfMinutes, mins);
            if(r+1<rows && !visited[r+1][c])
               { bfs.push({r+1,c,mins+1}); visited[r+1][c] = true; }
            if(r-1>=0 && !visited[r-1][c])
                { bfs.push({r-1,c,mins+1}); visited[r-1][c]=true; }
            if(c+1<cols && !visited[r][c+1])
               { bfs.push({r,c+1,mins+1}); visited[r][c+1] = true; }
            if(c-1>=0 && !visited[r][c-1])
              {  bfs.push({r,c-1,mins+1}); visited[r][c-1]=true; }
        }
        
        for(int i = 0;i<rows;i++) //checking if any cell of the grid is not visited yet
        {
            for(int j=0;j<cols;j++)
            {
                if(!visited[i][j])
                    return -1;
            }
        }
        
        return noOfMinutes;
    }
};