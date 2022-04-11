class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> temp;
        k = k%(grid.size()*grid[0].size());
        for(int i = 0; i<grid.size(); i++)
            for(int j = 0; j<grid[0].size(); j++)
                temp.push_back(grid[i][j]);
        int l = temp.size()-k;
        int n = temp.size();
        for(int i = 0; i<grid.size(); i++)
            for(int j = 0; j<grid[0].size(); j++)
                grid[i][j] = temp[(l++)%n];
        return grid;
    }
};