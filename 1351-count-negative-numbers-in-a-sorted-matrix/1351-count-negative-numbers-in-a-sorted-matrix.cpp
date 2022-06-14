class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int i = 0, j = grid[0].size()-1;
        int neg = 0;
        for(; i<grid.size() && j>=0;)
            if(grid[i][j]<0) --j, neg += grid.size()-i; //counting all negatives in the current column
            else ++i;
        return neg;
    }
};