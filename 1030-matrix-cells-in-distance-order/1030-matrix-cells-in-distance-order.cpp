class Solution {
public:
    
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;
        for(int i = 0; i<rows; ++i) 
            for(int j= 0; j<cols; ++j)
                ans.push_back({i,j});
        sort(ans.begin(),ans.end(),[&](const vector<int>&a, const vector<int>&b){
            return abs(a[0]-rCenter) + abs(a[1]-cCenter) < abs(b[0]-rCenter) + abs(b[1]-cCenter);
        });
        return ans;
    }
};