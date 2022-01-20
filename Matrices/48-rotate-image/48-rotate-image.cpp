class Solution {
public://ALGO: transpose then reverse each row; found just by looking at the matrix
    void rotate(vector<vector<int>>& matrix) {
        
        //computing transpose of current matrix
        for(int i = matrix.size()-1; i>=0 ; i--)
        {
            for(int j = matrix[0].size()-1; j>i ; j--)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //reversing each row
        for(auto &row: matrix)
            reverse(row.begin(),row.end());
    }
};