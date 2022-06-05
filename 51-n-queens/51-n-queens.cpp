class Solution {
public:
    
    bool isPossible(int row, int col, vector<string>& board, int n)
    {
        //We only check for existing queen(s) on the left side of current position because we're traversing from column 0 to n-1(i.e. left to right), 
        //so there's no use to check the right side as there'd be no queens placed yet.
        int rr = row, cc = col;
        //checking upper left diagonal
        while(rr>=0 && cc>=0)
        {
            if(board[rr][cc]=='Q') return false;
            --rr,--cc;
        }
        rr = row, cc = col;
        //checking left side horizontally
        while(cc>=0)
        {
            if(board[rr][cc]=='Q') return false;
            --cc;
        }
        cc = col;
        //checking lower left diagonal
        while(rr<n && cc>=0)
        {
            if(board[rr][cc]=='Q') return false;
            ++rr,--cc;
        }
        
        return true;
    }
    
    void util(int col, vector<string>&board, vector<vector<string>>&ans,int n)
    {
        if(col==n)
        {ans.push_back(board); return;}
        
        for(int row = 0; row<n; ++row)
            if(isPossible(row,col,board,n))
            {
                board[row][col] = 'Q';
                util(col+1,board,ans,n);
                board[row][col] = '.';
            }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n,'.'));
        util(0,board,ans,n);
        return ans;
    }
};