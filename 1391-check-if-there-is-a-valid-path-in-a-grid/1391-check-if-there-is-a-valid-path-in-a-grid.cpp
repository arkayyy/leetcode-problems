class Solution {
    //INTUITION: Simple DFS
    
    //ALGO: We keep a visited array and perform DFS from (0,0). For each kind of road we encounter, we see whether we can move up, down, left or right.
    //Also, the connectivity of current road and the next grid cell road must match (that can be determined and set as per the diagrams given in the question).
    //e.g.only streets 1,4 and 6 can accept coming leftwards from another cell to it.(since only 1,4 and 6 have an incoming road on the right)
public:
    bool isValid(int x,int y,vector<vector<int> > &grid)
    {
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size())
            return 0;
        return 1;
    }
    void dfs(int x,int y,vector<vector<bool> > &visited,vector<vector<int> > &grid){
        if(visited[x][y])
            return;
        visited[x][y] = 1;
        
        int up = 0,down = 0,left = 0,right = 0;

        //marking directions in which we can move as per the current type of road as 1 (true)
        if(grid[x][y] == 1)
            left=right=1;
        else if(grid[x][y] == 2)
            up=down=1;
        else if(grid[x][y] == 3)
            left=down=1;
        else if(grid[x][y] == 4)
            down=right=1;
        else if(grid[x][y] == 5)
            up = left = 1;
        else //if(grid[x][y]==6)
            right=up=1;
        
        //Now moving in each direction by DFS (if the move is valid)
        if(up) //if we can move up
        {
            int xx=x-1,yy=y;
            if(isValid(xx,yy,grid) && (grid[xx][yy]==2 || grid[xx][yy]==3 || grid[xx][yy]==4))
               dfs(xx,yy,visited,grid);
        }
        if(down) //if we can move up
        {
            int new_x=x+1,new_y=y;
            if(isValid(new_x,new_y,grid) && (grid[new_x][new_y]==2 || grid[new_x][new_y]==5 || grid[new_x][new_y]==6))
               dfs(new_x,new_y,visited,grid);
        }
        if(left) //if we can move to left
       {
            int new_x=x,new_y=y-1;
            if(isValid(new_x,new_y,grid) && (grid[new_x][new_y]==1 || grid[new_x][new_y]==4 || grid[new_x][new_y]==6))
               dfs(new_x,new_y,visited,grid);
       }
        if(right) //if we can move to right
       {
            int new_x=x,new_y=y+1;
            if(isValid(new_x,new_y,grid) && (grid[new_x][new_y]==1 || grid[new_x][new_y]==3 || grid[new_x][new_y]==5))
                dfs(new_x,new_y,visited,grid);
       }
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        if(!n) //no roads, so already reached end
            return 1;
        int m = grid[0].size();
        vector <vector<bool> > visited(n,vector<bool>(m,0));
        dfs(0,0,visited,grid);
        return visited[n-1][m-1];
    }
};