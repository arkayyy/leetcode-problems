class Solution {
public:
    int candy(vector<int>& ratings) {
        int up = 0, down = 0, peak = 0;
        int ans = 1;
        for(int i = 1; i<ratings.size(); ++i)
        {
            if(ratings[i]>ratings[i-1])
            {
                peak = ++up;
                down = 0;
                ans += 1+up;
            }
            else if(ratings[i]==ratings[i-1])
            {
                peak = up = down = 0;
                ans+=1;
            }
            else if(ratings[i]<ratings[i-1])
            {
                ++down;
                up = 0;
                ans += down + (down>peak?1:0);
            }
        }
        return ans;
    }
};