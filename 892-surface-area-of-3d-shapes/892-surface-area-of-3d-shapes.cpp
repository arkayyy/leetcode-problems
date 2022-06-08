class Solution {
public:
    //INTUITION: Let us consider that every height contributes to the surface area according to its difference with the smaller heights adjacent to it.
    int surfaceArea(vector<vector<int>>& grid) {
        int sarea = 0;
        int n = grid.size(), m = grid[0].size();
        if(n==1 && m==1) return 2+(grid[0][0]*4);
        for(int i = 0; i<n;++i)
            for(int j = 0; j<m; ++j)
            {
                if((i==0 && j==0) || (i==n-1 && j==m-1) || (i==0&&j==m-1) || (i==n-1 && j==0)) sarea+=2*grid[i][j]; //for corner heights 2 extra sides
                else if(i==0 || j==0 || i==n-1 || j==m-1) sarea+=grid[i][j]; //for other cells at boundaries 1 extra side
                
                sarea += max(0, i+1<n?grid[i][j]-grid[i+1][j]:0);
                sarea += max(0, i-1>=0?grid[i][j]-grid[i-1][j]:0);
                sarea += max(0, j+1<m?grid[i][j]-grid[i][j+1]:0);
                sarea += max(0, j-1>=0?grid[i][j]-grid[i][j-1]:0);
                
                sarea+=grid[i][j]?2:0; //for top and bottom
            }
        return sarea;
    }
};