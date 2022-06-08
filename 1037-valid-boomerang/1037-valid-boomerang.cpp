class Solution {
public:
    //slope b/w 1st and 2nd pt != slope b/w 2nd and 3rd pt
    
    bool isBoomerang(vector<vector<int>>& points) {
        return (points[1][1]-points[0][1])*(points[2][0]-points[1][0]) != (points[2][1]-points[1][1])*(points[1][0]-points[0][0]);
    }
};