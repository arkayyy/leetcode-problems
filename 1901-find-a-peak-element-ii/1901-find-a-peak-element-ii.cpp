class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        //INTUITION & ALGO: We apply binary search on columns, and for every column that we assess, we find the row having max element. \
        //Because obviously the max element will be greater than the upper element (previous row element same column) and lower element(next row element same column)
        //So upper and lower condition of peak element is satisfied. 
        //Now we check if this max element also is bigger than its left(previous column same row) and right(next column same row) element.
        //If yes, then peak element is FOUND!
        
        int lo = 0, hi = mat[0].size()-1;
        while(lo<=hi)
        {
            int mid = lo+((hi-lo)>>1);
            int maxRowIdx = 0;
            for(int i = 0; i<mat.size(); ++i) if(mat[i][mid]>mat[maxRowIdx][mid]) maxRowIdx = i; //finding max element row in the whole column

            if((mid-1<0 || mat[maxRowIdx][mid]>=mat[maxRowIdx][mid-1]) && (mid+1>mat[0].size()-1 || mat[maxRowIdx][mid]>mat[maxRowIdx][mid+1])) return {maxRowIdx, mid};
            
            //going in the direction of the rising slope(by choosing the element which is greater than current)
            //there are 2 possibilities:-
            //a) rising slope has to keep rising till end of the array 
            //b) rising slope will encounter a lesser element and go down 
            
            if((mid-1<0 || mat[maxRowIdx][mid]>=mat[maxRowIdx][mid-1])) //only greater than left, not right. so rising slope towards right
                lo=mid+1;
            else //only greater than right,not left
                hi=mid-1;
        }
        return {-1,-1};
    }
};