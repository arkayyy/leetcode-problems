class Solution {
public:
    
    void dfs(int r, int c, vector<vector<char>>& grid)
    {
        if(r>=grid.size() || c>=grid[0].size() || r<0 || c<0 || grid[r][c]=='0')
            return;
        
        grid[r][c] = '0';
        
        dfs(r+1,c,grid);
        dfs(r-1,c,grid);
        dfs(r,c+1,grid);
        dfs(r,c-1,grid);
       
    }
    int numIslands(vector<vector<char>>& grid) {
        
        //USING DFS:-
        int cnt = 0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
        
        
        
        
        
        //USING BFS:-
        
//         queue<pair<int,int>> q;
        
        
//         int m = grid.size(), n=grid[0].size();
        
//         int cnt = 0;
        
//         for(int i=0;i<m; i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(grid[i][j]=='1')
//                 {
//                     q.push({i,j});
//                     cnt++;
                    
                    
//                     while(!q.empty())
//                     {
//                         int len = q.size();
//                         for(int k=0; k<len;k++)
//                         {
                            
//                             pair<int,int> coords = q.front(); q.pop();
                            
//                             int p = coords.first, r = coords.second;
                           
                            
//                             if(p+1<m && grid[p+1][r]=='1')
//                                 { grid[p+1][r]=0; q.push({p+1,r});}
//                             if(p-1>=0 && grid[p-1][r]=='1')
//                                {grid[p-1][r]=0; q.push({p-1,r});}
//                             if(r+1<n && grid[p][r+1]=='1')
//                                {grid[p][r+1]=0; q.push({p,r+1});}
//                             if(r-1>=0 && grid[p][r-1]=='1')
//                                 {grid[p][r-1] = 0; q.push({p,r-1});}
                            
                            
                            
//                         }
                            
//                     }
//                 }
//             }
//         }
        
//         return cnt;
    }
};