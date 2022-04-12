class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        
        for(int i = 0; i<board.size(); i++)
        {
            for(int j = 0; j<board[0].size(); j++)
            {
                int live = 0;
                live+= ((i-1>=0)?board[i-1][j]:0) + ((i+1<n)?board[i+1][j]:0);
                live+= ((j-1>=0)?board[i][j-1]:0) + ((j+1<m)?board[i][j+1]:0);
                live+= ((i-1>=0 && j-1>=0)?board[i-1][j-1]:0) + ((i-1>=0 && j+1<m)?board[i-1][j+1]:0);
                live+= ((i+1<n && j-1>=0)?board[i+1][j-1]:0) + ((i+1<n && j+1<m)?board[i+1][j+1]:0);
                if(board[i][j]==1)
                {
                    if( (live<2 || live>3))
                        ans[i][j] = 0;
                    else if(live==2 || live==3)
                        ans[i][j] = 1;
                }
                else if(live==3)
                    ans[i][j]=1;  
            }
        }
        board = ans;
    }
};