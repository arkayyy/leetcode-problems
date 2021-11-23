class Solution {
public:
    struct qt{
        int i = -1;
        int j = -1;
        int steps = 0;
        qt(int a,int b,int c)
        {
            i=a; j=b; steps=c;
        }
    };
    int orangesRotting(vector<vector<int>>& grid) {
       
        
        int r=grid.size(), c = grid[0].size();
        vector<vector<bool>> v (r,vector<bool>(c,false));
        
         int ri = -1, rj = -1;
        
        int cntNonEmpty = 0;
        
        
         queue<qt*> q;
        
        
        for(int i=0;i<r;i++)
        {
            for(int j = 0;j<c;j++)
                {
                    if(grid[i][j]==2) //storing the position of the rotten oranges, along with the steps taken uptil that orange
                    {q.push(new qt(i,j,0)); }
                
                    if(grid[i][j]==1) cntNonEmpty++; //counting all cells where oranges (rotten or fresh) are present initially.
                }       
        }
        
        if(cntNonEmpty==0)
            return 0;

        int minsteps = 0;
       
        while(!q.empty())
        {
            qt* t = q.front();
            q.pop();
            int i = t->i, j=t->j, steps = t->steps; 
            
            minsteps = max(minsteps,steps);
            
            //checking for fresh oranges in all four directions
            if(i+1<r && grid[i+1][j]!=0 && grid[i+1][j]!=2  && !v[i+1][j])
                {grid[i+1][j] = 2; q.push(new qt(i+1,j,steps+1)); v[i+1][j] = true;}
            
            if(i-1>=0 && grid[i-1][j]!=0 && grid[i-1][j]!=2  && !v[i-1][j])
                {grid[i-1][j] = 2; q.push(new qt(i-1,j,steps+1)); v[i-1][j] = true; }
            
            if(j+1<c && grid[i][j+1]!=0 && grid[i][j+1]!=2  && !v[i][j+1])
                {grid[i][j+1] = 2; q.push(new qt(i,j+1,steps+1)); v[i][j+1] = true;}
            
            if(j-1>=0 && grid[i][j-1]!=0  && grid[i][j-1]!=2 && !v[i][j-1])
                {grid[i][j-1] = 2; q.push(new qt(i,j-1,steps+1)); v[i][j-1] = true; }
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(v[i][j])
                    cntNonEmpty--;   //counting that if all cells that had oranges have been visited and are now rotten
            }
        }
        if(!cntNonEmpty)
        return minsteps;
        
        return -1;
    }
};