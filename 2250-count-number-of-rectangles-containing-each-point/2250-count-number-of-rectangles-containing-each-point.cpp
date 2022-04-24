class Solution {
public:
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
                sum+= mp[i].end() - lower_bound(mp[i].begin(),mp[i].end(),x);
            ans.push_back(sum);
        }
        
        return ans;
    }
};