class Solution {
public:
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