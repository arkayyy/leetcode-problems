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
        for(auto row: matrix)
    {
        if(target>=row[0] && target<=row[matrix[0].size()-1])
        {
            if(binSearch(row,target)) return true;
            else return false;
        }
    }
    return false;
    }
};