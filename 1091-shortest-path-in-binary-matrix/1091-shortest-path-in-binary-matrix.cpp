class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int dx[8] = {0,0,1,1,1,-1,-1,-1};
        int dy[8] = {1,-1,-1,0,1,-1,0,1};

        int n = grid.size(), m = grid[0].size();
        if(n==1 && m==1) return grid[0][0]==0;
        vector<vector<bool>> visited(n, vector<bool> (m,false));
        int ans = 1;
        queue<vector<int>> q;
        q.push({0,0,1});
        while(!q.empty())
        {
            int x = q.front()[0], y = q.front()[1];
            int steps = q.front()[2];
            
            q.pop();
            ++ans;
            for(int i = 0; i<8; ++i)
                {
                if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<m && grid[x+dx[i]][y+dy[i]]==0 &&  !visited[x+dx[i]][y+dy[i]])
                   { if(x+dx[i]==n-1 && y+dy[i]==m-1) return steps+1; visited[x+dx[i]][y+dy[i]] = true; q.push({x+dx[i], y+dy[i], steps+1});}}
        }
        
        return -1;
    }
};