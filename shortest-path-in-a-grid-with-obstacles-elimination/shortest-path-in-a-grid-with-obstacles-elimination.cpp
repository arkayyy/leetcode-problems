class Solution {
public:
    struct elem{
        int x;
        int y;
        int k;
        int dist;
        
        elem(int _x,int _y,int _k, int _dist)
        {
            x=_x; y=_y; k=_k; dist = _dist;
        }
    };
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<elem*> q;
        
        q.push(new elem(0,0,k,0));
        
        int r = grid.size(), c = grid[0].size();
        
        int mini = INT_MAX;
        
        vector<vector<vector<bool>>> v( r,vector<vector<bool>>(c,vector<bool>(k+1,false)));
        
        v[0][0][k] = true;
        
        while(!q.empty())
        {
            int x = q.front()->x;
            int y = q.front()->y;
            int kleft = q.front()->k;
            int dist = q.front()->dist;
            
            q.pop();
            
            if(x==r-1 && y == c-1)
                return dist;
            
            //checking in all 4 directions
            if(x+1<r && !v[x+1][y][kleft])
            {
                if(grid[x+1][y]==1)
                {
                    if(kleft>0)
                        q.push(new elem(x+1,y,kleft-1,dist+1));
                }
                else
                {
                    q.push(new elem(x+1,y,kleft,dist+1));
                }
                v[x+1][y][kleft] = true;
            }
            
            if(x-1>=0 && !v[x-1][y][kleft])
            {
                if(grid[x-1][y]==1)
                {
                    if(kleft>0)
                        q.push(new elem(x-1,y,kleft-1,dist+1));
                }
                else
                {
                    q.push(new elem(x-1,y,kleft,dist+1));
                }
                v[x-1][y][kleft] = true;
            }
            
            if(y+1<c && !v[x][y+1][kleft])
            {
                if(grid[x][y+1]==1)
                {
                    if(kleft>0)
                        q.push(new elem(x,y+1,kleft-1,dist+1));
                }
                else
                {
                    q.push(new elem(x,y+1,kleft,dist+1));
                }
                v[x][y+1][kleft] = true;
            }
            
            if(y-1>=0 && !v[x][y-1][kleft])
            {
                if(grid[x][y-1]==1)
                {
                    if(kleft>0)
                        q.push(new elem(x,y-1,kleft-1,dist+1));
                }
                else
                {
                    q.push(new elem(x,y-1,kleft,dist+1));
                }
                v[x][y-1][kleft] = true;
            }
            
            
            
        }
        
        
        return -1;
    
    }
};