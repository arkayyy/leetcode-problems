class Solution {
public:
    //INTUITION: Brute force, checking every point inside the  sqauare of side 2r to lie inside the circle
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>> s;
        for(auto c: circles)
        {
            int x = c[0], y = c[1], r = c[2];
            for(int i=x-r;i<=x+r;i++)
                for(int j=y-r;j<=y+r;j++)
                    if(sqrt((x-i)*(x-i) + (y-j)*(y-j)) <= r)      //checks if distance of point from center <= radius
                        s.insert({i,j});
        }
        return s.size();
    }
};