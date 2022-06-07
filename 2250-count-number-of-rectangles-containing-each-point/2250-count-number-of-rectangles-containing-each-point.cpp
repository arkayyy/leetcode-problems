class Solution {
public:
    //INTUITION: Since the constraints for y coordinates is less (only upto 100), So for every y coordinate we store all associated x coordinates of the upper corners of the rectangles
    //Later for every point, we check for every y coordinate between that point's y coordinate and 100, and their possible x coordinates in rectangle for containing the point
    
    int binsearch(vector<int>& arr, int x){
        int l=0, r=arr.size()-1;

        int ans=arr.size(); 
        // if we find no m such that arr[m]>=x, means that our x is greater than all values of length, in such case we return idx n (i.e. size of arr)
        // reason being, we substract our idx by size of arr to get number of rectangles greater than that in main fxn, so return arr.size would give us 0 (which we want)

        while(l<=r){
            int m= l + (r-l)/2;


            if(arr[m]>=x){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }

        }

        return ans;
    }
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
                sum+= mp[i].size() - binsearch(mp[i],x); //binary search will give the position of the rectangle upper point's x coordinate that is just more than or equal to (i.e. not less than) the given value of x (in point)
            //This will ensure that all such rectangles are counted whose upper corner's x coordinate is more than this given point's x coordinate...
            //...because only those rectangles can contain this point!
            ans.push_back(sum);
        }
        
        return ans;
    }
};