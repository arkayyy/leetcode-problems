class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b)     {
        int m = 0; //to traverse in the first list
        int n = 0; //to traverse in the second list
        
        vector<vector<int>> ans;
        
        while(m<a.size() && n<b.size())
        {
            int start1 = a[m][0], end1 = a[m][1];
            int start2 = b[n][0], end2 = b[n][1];
            
            if(start1>=start2 && end1<=end2) // e.g. for common interval b/w [0,5] and [1,3]
            {
                ans.push_back({start1,end1});
                m++;
            }
            else if(start2>=start1 && end2<=end1) //e.g. for common interval b/w [1,3] and [0,5]
            {
                ans.push_back({start2,end2});
                n++;
            }
            
            else if(start1<start2 && end1>=start2 && end1<=end2) // for common interval b/w [0,4] and [1,2]
            {
                ans.push_back({start2,end1});
                m++;
            }
            else if(start2<start1 && end2>=start1 && end2<=end1) //for common interval b/w [1,2] and [0,4]
            {
                ans.push_back({start1,end2});
                n++;
            }
            else if(start2>end1) //moving pointer of 1st array if the 2nd array range is totally separate and ahead of the 1st array range
                m++;
            else  //if(start1>end2)//moving pointer of 2nd array if the 1st array range is totally separate and ahead of the 2nd array range
                n++;
        }
        
        return ans;
    }
};