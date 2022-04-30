class Solution {
    //INTUITION: We can first calculate the min. time taken for fire to reach each cell of the grid.
    //We can then minimise the value of wait time as per criteria to successfully reach the safehouse.
    
    //ALGO: To fill the minimum fire reaching time for each cell, we use BFS.
    //For checking if user can reach the safehouse after a certain wait time also, we use BFS.
    //BFS is used because by default without hassle it always considers the shortest path/time.
    private:
    vector<int> fx = {-1,1,0,0};
    vector<int> fy = {0,0,-1,1};
    bool invalid(int n,int m, int i, int j, vector<vector<int>>& grid)
    {
        return (i<0 || j<0 || i>=n || j>=m || grid[i][j]==2);
    }
    
    void fireSpread(vector<vector<int>>& grid, vector<vector<int>>&fireReachTime) //calculating time fire takes to reach for each cell in the grid
    {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        fireReachTime = vector<vector<int>>(300,vector<int>(300,INT_MAX)); 
        //Marking already fired up points as source of BFS
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++)
                if(grid[i][j]==1)
                    q.push({i,j}), fireReachTime[i][j] = 0;
        //BFS:-
        while(!q.empty())
        {
            int x = q.front().first, y = q.front().second; q.pop();
            for(int i = 0; i<4;i++)
            {
                int xx = x+fx[i], yy = y+fy[i]; 
                if(invalid(n,m,xx,yy,grid)) continue;
                if(fireReachTime[xx][yy] > fireReachTime[x][y]+1)
                    fireReachTime[xx][yy] = fireReachTime[x][y]+1, q.push({xx,yy});
            }
        }
    }
    
    int safehouseTime(int wait, vector<vector<int>>& grid, vector<vector<int>>& myReachTime, vector<vector<int>>&fireReachTime)
    {
        int n = grid.size(), m = grid[0].size();
        myReachTime = vector<vector<int>>(300,vector<int>(300,INT_MAX));
        queue<pair<int,int>> q;
        q.push({0,0}); //our starting pt.
        myReachTime[0][0] = wait;
        while(!q.empty())
        {
            int x = q.front().first, y = q.front().second; q.pop();
            for(int i = 0;i<4;i++)
            {
                int xx = x+fx[i], yy = y+fy[i]; 
                if(invalid(n,m,xx,yy,grid)) continue;
                int newMyReachTime = min(myReachTime[xx][yy],myReachTime[x][y]+1); //updated min. time to reach index [xx][yy]
                if(xx==n-1 && yy==m-1 && newMyReachTime<=fireReachTime[xx][yy]) return newMyReachTime;//reached safehouse
                if(newMyReachTime >= fireReachTime[xx][yy]) continue; //No use of updating, already minimum time stored
                if(myReachTime[xx][yy] > myReachTime[x][y]+1)
                    myReachTime[xx][yy] = myReachTime[x][y]+1 , q.push({xx,yy});
            }
        }
        
        return INT_MAX;
    }
public:
    int maximumMinutes(vector<vector<int>>& grid) {
            vector<vector<int>> fireReachTime(300,vector<int>(300));
    vector<vector<int>> myReachTime(300,vector<int>(300));
        
        int n = grid.size(), m = grid[0].size();
        fireSpread(grid, fireReachTime); //filling the fireReachTime for each cell grid position
        
        if (fireReachTime[n - 1][m - 1] == INT_MAX) { //EDGE CASE 1: If fire can't ever reach the safehouse
            return safehouseTime(0, grid,myReachTime, fireReachTime) < INT_MAX ? 1e9 : -1; //We only need to check if the user can get to safehouse (no need of bothering abt wait time)
        }
        
        //Binary search to find the minimum waiting time:-
        int lo = 0, hi = (n*m)+1, maxWaitTime = -1;
        while(lo <= hi) {
            int mid = ((lo + hi) >> 1);
            if (safehouseTime(mid, grid, myReachTime,fireReachTime) <= fireReachTime[n - 1][m - 1])//we can reach safehouse before fire reaches with a wait time of 'mid'
                lo = mid + 1, maxWaitTime = mid;
            else 
                hi = mid - 1;
        }
        
        return maxWaitTime == ((n*m)+1) ? 1e9 : maxWaitTime;
    }
};