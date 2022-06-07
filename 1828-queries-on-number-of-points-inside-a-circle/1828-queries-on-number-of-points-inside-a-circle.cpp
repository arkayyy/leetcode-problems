class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans; ans.reserve(queries.size());
        
        for(auto q: queries)
        {
            int x = q[0], y = q[1], r = q[2];
            int cnt = 0;
            for(auto p: points)
            {
                int a = p[0], b = p[1];
                if(pow(x-a,2)+pow(y-b,2)<=pow(r,2))
                    ++cnt;
            }
            ans.emplace_back(cnt);
        }
        return ans;
    }
};