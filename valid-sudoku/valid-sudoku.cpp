class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowCheck[9][9] = {0}; // rowCheck[k][num] is 1 iff num is already present in the kth row
        int colCheck[9][9] = {0}; // colCheck[k][num] is 1 iff num is already present in kth column
        
        int subBoxCheck[9][9] = {0}; //subBoxCheck[k][num] is true if the kth sub box already contains num
        
        for(int i = 0; i<9;i++)
        {
            for(int j = 0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int num = board[i][j]-'0'-1;
                    int k = i/3*3 + j/3; //k is the subbox number. basically we are mapping all 9 cells in a subbox to a same value using this special formula. 
                    if(rowCheck[i][num] || colCheck[j][num] || subBoxCheck[k][num]) //number already found in either same row, column or subbox
                        return false;
                    rowCheck[i][num] = colCheck[j][num] = subBoxCheck[k][num] = 1;
                }
            }
        }
        return true;
    }
};