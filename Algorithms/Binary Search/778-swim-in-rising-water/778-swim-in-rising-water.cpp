class Solution {
public:
    vector<vector<int>> dir{ {1,0}, {-1,0},{0,1}, {0,-1} };
    bool canReachEnd(int i, int j, int level, vector<vector<bool>>&visited,int n, vector<vector<int>>& grid)
    {
        if(i==n-1 && j==n-1) return true;
        visited[i][j] = true;
        //checking in all 4 adjacent cells
        for(auto d: dir)
        {
            if(i+d[0]>=0 && i+d[0]<n && j+d[1]>=0 && j+d[1]<n && !visited[i+d[0]][j+d[1]] && grid[i+d[0]][j+d[1]]<=level)
            {
                if(canReachEnd(i+d[0],j+d[1],level, visited,n,grid)) //dfs call
                    return true;
            }
        }
        
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(n==1 && m==1) return grid[0][0];
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        visited[0][0] = true;
        
        //--------------------APPROACH - 1 ---------------------------------------//
        //DFS approach with Binary Search implementation:-
        int lo =grid[0][0], hi = n*n , mid;
        while(lo<=hi)
        {
            mid = lo+((hi-lo)>>1);
            if(canReachEnd(0,0,mid,visited,n,grid)) //if can reach end, we try to minimise the level
            {
                hi = mid-1;
            }
            else
                lo = mid+1;
            fill(visited.begin(),visited.end(),vector<bool>(m,false));
        }
        return lo;
        
        
        //------------------APPROACH - 2 -----------------------------------------//
//         //BFS approach with Djikstra implementation:-
        
//         priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
//         int ans = max(grid[0][0], grid[n-1][n-1]);
        
//         pq.push({grid[0][0], 0, 0}); 
//         while(!pq.empty())
//         {
//             vector<int> temp = pq.top();
//             int level = temp[0], r = temp[1], c = temp[2];
//             pq.pop();
//             ans = max(ans,level); //since we are doing Djikstra's we are going to be following the least elevation path first...
//             //...so the maximum elevation out of this least elevation path will be our answer 
            
//             //checking in all 4 adjacent cells:- 
//             if(r+1<n && !visited[r+1][c])
//             {
//                 if(r+1==n-1 && c==m-1) return ans;
//                 pq.push({grid[r+1][c],r+1,c});
//                 visited[r+1][c] = true;
//             }
//             if(r-1>=0 && !visited[r-1][c])
//             {
//                 if(r-1==n-1 && c==m-1) return ans;
//                 pq.push({grid[r-1][c],r-1,c});
//                 visited[r-1][c]= true;
//             }
//             if(c+1<m && !visited[r][c+1])
//             {
//                 if(r==n-1 && c+1==m-1) return ans;
//                 pq.push({grid[r][c+1], r, c+1});
//                 visited[r][c+1] = true;
//             }
//             if(c-1>=0 && !visited[r][c-1])
//             {
//                 if(r==n-1 && c-1==m-1) return ans;
//                 pq.push({grid[r][c-1],r,c-1});
//                 visited[r][c-1] = true;
//             }
//         }
        
//         return -1;
    }
};