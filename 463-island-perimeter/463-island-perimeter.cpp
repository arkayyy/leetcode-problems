class Solution {
public:
    //INTUITION: At every land, the perimeter would be reduced only at the side where land is present...
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri=0;
        for(int i = 0; i<grid.size(); i++)
            for(int j =0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==1)
                {int t = 4;
                if(i-1>=0 && grid[i-1][j]==1)
                    --t;
                if(i+1<grid.size() && grid[i+1][j]==1)
                    --t;
                if(j-1>=0 && grid[i][j-1]==1)
                    --t;
                if(j+1<grid[0].size() && grid[i][j+1]==1)
                    --t;
                peri+=t;}
            }
        return peri;
    }
};