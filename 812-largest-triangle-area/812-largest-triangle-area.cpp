class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0.00000;
        for(int i = 0; i<points.size(); ++i)
            for(int j = 0; j<points.size(); ++j)
                if(i!=j)
                    for(int k = 0; k<points.size(); ++k)
                        if(k!=i and k!=j)
                        {
                            ans = max(ans, 0.50000 * (points[i][0]*points[j][1] + points[j][0]*points[k][1] + points[k][0]*points[i][1] - points[i][1]*points[j][0] - points[j][1]*points[k][0] - points[k][1]*points[i][0]));
                        }
        return ans;
    }
};