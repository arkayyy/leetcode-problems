class Solution {
public:
    //INTUITION: Similar to LC221-Maximal Sqaure in a matrix
    //Everytime we have a chance to expand the square we do that. And we keep adding the total no. of sqaures made using each 1 in the grid.
    
    //See notes for visual explanation: https://github.com/arkayyy/leetcode-problems/blob/main/1277-count-square-submatrices-with-all-ones/HW%20Notes.pdf
    int countSquares(vector<vector<int>>& matrix) {
        int squares = 0;
        for(int i = 0; i<matrix.size(); i++)
            for(int j = 0; j<matrix[0].size(); j++)
            {
                if(matrix[i][j]==0) continue;
                if(i==0 || j==0) ++squares;
                else squares+=(matrix[i][j]=1+min({matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]}));
            }
        return squares;
        
    }
    
};