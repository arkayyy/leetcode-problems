class Solution {
public:
    //INTUITION: The idea is to first calculate the slope b/w first 2 points. 
    //In order for all pts to be on a straight line, all lines should also have this exact same slope with the point at 0th index.
    
    //let slope b/w first 2 points = dy/dx
    //and slope b/w any  other pt and 0th index point = dy1/dx1
    //for them to lie on straight line, dy1*dx1 = dy/dx ...cross multiplying we get the condition as: dy1*dx = dx1*dy
    bool checkStraightLine(vector<vector<int>>& coords) {
        int dy = coords[1][1]-coords[0][1];
        int dx = coords[1][0]-coords[0][0];
        for(int i = 2; i<coords.size(); ++i) if((coords[i][1]-coords[0][1])*dx != (coords[i][0]-coords[0][0])*dy) return false;
        return true;
    }
    
};