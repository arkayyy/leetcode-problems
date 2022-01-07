class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //ALGO: We will use the first row and first column elements as the indicator for rest of the matrix. They will act like the heads of each row and column. 
        //If any of them is zero that indicates that whole row or column will become 0.
        
        bool firstRowZero=false, firstColZero=false;
        for(int j = 0; j<matrix[0].size(); j++)
        {
            if(matrix[0][j]==0){ firstRowZero = true; break;} //setting indicator if any 0 is present in the first(0 index) row itself
        }
        
        for(int  i= 0; i<matrix.size(); i++)
        {
            if(matrix[i][0]==0) {firstColZero = true; break;} //setting indicator if any 0 is present in the first (0th) column itself
        }
        
        for(int i = 1; i<matrix.size(); i++)
        {
            for(int j = 1; j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i<matrix.size(); i++)
        {
            for(int j = 1; j<matrix[0].size();j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0; //making an element 0 if the head of its row or head of its column is zero.
                }
            }
        }
        
        if(firstRowZero)
            for(int j = 0; j<matrix[0].size(); j++)
                matrix[0][j] = 0; //if the first row itself has 0, then we make the whole first row zero separately
        if(firstColZero)
            for(int i = 0; i<matrix.size(); i++)
                matrix[i][0] = 0; //if the first column itself has 0, then we make the whole first row zero separately
    }
};