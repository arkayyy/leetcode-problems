class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowZero=false, lastRowZero=false, firstColZero=false, lastColZero=false;
        for(int j = 0; j<matrix[0].size(); j++)
        {
            if(matrix[0][j]==0) firstRowZero = true;
            if(matrix[matrix.size()-1][j]==0) lastRowZero = true;
        }
        
        for(int  i= 0; i<matrix.size(); i++)
        {
            if(matrix[i][0]==0) firstColZero = true;
            if(matrix[i][matrix[0].size()-1]==0) lastColZero = true;
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
                    matrix[i][j]=0;
                }
            }
        }
        
        if(firstRowZero)
            for(int j = 0; j<matrix[0].size(); j++)
                matrix[0][j] = 0;
        if(lastRowZero)
            for(int j = 0; j<matrix[0].size(); j++)
                matrix[matrix.size()-1][j] = 0;
        if(firstColZero)
            for(int i = 0; i<matrix.size(); i++)
                matrix[i][0] = 0;
        if(lastColZero)
            for(int i = 0; i<matrix.size(); i++)
                matrix[i][matrix[0].size()-1] = 0;
    }
};