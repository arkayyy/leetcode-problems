class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(n==1 && m==1) return grid[0][0];
        
        //BFS approach with Djikstra implementation:-
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int ans = max(grid[0][0], grid[n-1][n-1]);
        
        pq.push({grid[0][0], 0, 0}); visited[0][0] = true;
        while(!pq.empty())
        {
            vector<int> temp = pq.top();
            int level = temp[0], r = temp[1], c = temp[2];
            pq.pop();
            ans = max(ans,level); //since we are doing Djikstra's we are going to be following the least elevation path first...
            //...so the maximum elevation out of this least elevation path will be our answer 
            
            //checking in all 4 adjacent cells:- 
            if(r+1<n && !visited[r+1][c])
            {
                if(r+1==n-1 && c==m-1) return ans;
                pq.push({grid[r+1][c],r+1,c});
                visited[r+1][c] = true;
            }
            if(r-1>=0 && !visited[r-1][c])
            {
                if(r-1==n-1 && c==m-1) return ans;
                pq.push({grid[r-1][c],r-1,c});
                visited[r-1][c]= true;
            }
            if(c+1<m && !visited[r][c+1])
            {
                if(r==n-1 && c+1==m-1) return ans;
                pq.push({grid[r][c+1], r, c+1});
                visited[r][c+1] = true;
            }
            if(c-1>=0 && !visited[r][c-1])
            {
                if(r==n-1 && c-1==m-1) return ans;
                pq.push({grid[r][c-1],r,c-1});
                visited[r][c-1] = true;
            }
        }
        
        return -1;
    }
};