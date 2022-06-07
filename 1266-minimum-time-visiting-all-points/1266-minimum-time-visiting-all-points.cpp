class Solution {
public:
    //INTUITION: for travelling between any two points, the minimum distance required would be the maximum difference b/w x or y coordinates
    //e.g. for travelling b/w (1,2) and (5,7)...diff in x coords = 5-1 = 4, and diff in y coords = 7-2 = 5.
    //So 4 units can be moved diagonally in order to travel while increasing both x and y coords. and the leftover 1 unit for travel in y direction is travelled individually
    //So the min. steps to travel b/w the 2 points becomes = 5 (i.e. max(4,5) = 5)
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i+1<points.size(); ++i) ans+=max(abs(points[i][0]-points[i+1][0]), abs(points[i][1]-points[i+1][1]));
        return ans;
    }
};