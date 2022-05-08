class Solution {
public:
    bool binSearch(vector<int>& arr, int target)
{
    int i = 0, j=arr.size()-1;
    int mid;
    while(i<=j)
    {
        mid = i+((j-i)>>1);
        if(arr[mid]==target) return true;
        if(target > arr[mid]) i = mid+1;
        else j = mid-1;
    }
    return false;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //======================APPROACH 1: Select row and binary search O(MlogN) Time O(1) space======================//
//         for(auto row: matrix)
//         {
//             if(target>=row[0] && target<=row[matrix[0].size()-1])
//             {
//                 if(binSearch(row,target)) return true;
//                 else return false;
//             }
//         }
//         return false;
        
        
        
        //=======================APPROACH 2: select both row and col by binary search O(logM + log N) Time O(1) Space=======================//
        //EDGE cases: 1 row, OR 1 column, OR the value outside the highest or lowest range in the matrix
        int n = matrix.size(), m = matrix[0].size();
        int lo = 0, hi = n-1;
        while(n>1 && lo<=hi)
        {
            int mid= lo+((hi-lo)>>1);
            if(matrix[mid][m-1]==target) return true;
            if(matrix[mid][m-1] < target)
                lo = mid+1;
            else
                hi = mid - 1;
        }
        if(lo>=n) return false;
        
        int row = lo;
        lo = 0, hi = m-1; 
        while(m>1 && lo<=hi)
        {
            int mid= lo+((hi-lo)>>1);
            if(matrix[row][mid]==target) return true;
            if(matrix[row][mid] < target)
                lo = mid+1;
            else
                hi =mid - 1;
        }
        
        return m==1?matrix[lo][0]==target:false;
    }
};