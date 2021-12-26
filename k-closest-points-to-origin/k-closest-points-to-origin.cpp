class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       vector<vector<int>> dist;
    
        for(auto i=0; i<points.size();i++)
        {
            dist.push_back({ (int)(pow(points[i][0],2)+pow(points[i][1],2)) , i});
        }
        
        sort(dist.begin(),dist.end());
        
        vector<vector<int>> ans;
        for(int i = 0;i<k;i++)
        {
            ans.push_back(points[dist[i][1]]);
        }
        
        return ans;
    }
};