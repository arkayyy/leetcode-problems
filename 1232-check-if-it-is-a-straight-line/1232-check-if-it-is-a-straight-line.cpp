class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coords) {
        int dy = coords[1][1]-coords[0][1];
        int dx = coords[1][0]-coords[0][0];
        for(int i = 2; i<coords.size(); ++i) if((coords[i][1]-coords[0][1])*dx != (coords[i][0]-coords[0][0])*dy) return false;
        return true;
    }
    
};