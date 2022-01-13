class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 0, minEnd = INT_MAX;
        sort(points.begin(), points.end());
        for(auto& p: points) {
            if(p[0] > minEnd) {count++; minEnd = p[1];}
            else minEnd = min(minEnd, p[1]);
        }
        return count + !points.empty();
    }
};