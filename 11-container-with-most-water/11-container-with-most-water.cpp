class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = INT_MIN;
        
        int l = 0, r = height.size()-1;
        
        while(l<r)
        {
            int h1 = height[l];
            int h2 = height[r];
            int area = min(h1,h2)*(r-l);
            maxarea = max(maxarea, area);
            if(h1<h2)
                l++;
            else
                r--;
        }
        
        return maxarea;
    }
};