class Solution {
public:
    //INTUITION: Since the constraints for y coordinates is less (only upto 100), So for every y coordinate we store all associated x coordinates of the upper corners of the rectangles
    //Later for every point, we check for every y coordinate between that point's y coordinate and 100, and their possible x coordinates in rectangle for containing the point
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        unordered_map<int,vector<int>> mp;
        for(auto rect: rectangles)
            mp[rect[1]].push_back(rect[0]);
        for(auto &m: mp)
            sort(m.second.begin(),m.second.end());
        vector<int> ans;
        for(auto p:points)
        {
            int x = p[0], y = p[1];
            int sum = 0;
            for(int i = y; i<=100; i++)
                sum+= mp[i].end() - lower_bound(mp[i].begin(),mp[i].end(),x); //lower bound will give the position of the rectangle upper point's x coordinate that is just more than (or not less than) the given value of x (in point)
            //This will ensure that all such rectangles are counted whose upper corner's x coordinate is more than this given point's x coordinate...
            //...because only those rectangles can contain this point!
            ans.push_back(sum);
        }
        
        return ans;
    }
};