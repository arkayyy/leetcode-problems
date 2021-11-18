class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>&board, vector<vector<bool>>&visited)
    {
        
        visited[i][j] = true;
        
        if(i+1<board.size() && board[i+1][j]=='O' && !visited[i+1][j])
            dfs(i+1,j,board,visited);
        if(i-1>=0 && board[i-1][j]=='O' && !visited[i-1][j])
            dfs(i-1,j,board,visited);
        if(j+1<board[0].size() && board[i][j+1]=='O' && !visited[i][j+1])
            dfs(i,j+1,board,visited);
        if(j-1>=0 && board[i][j-1]=='O' && !visited[i][j-1])
            dfs(i,j-1,board,visited);
        
    }
    void solve(vector<vector<char>>& board) {
        
        
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        
        for(int i = 0; i<n;i++)
        {
            if(board[0][i]=='O' && !visited[0][i])
                dfs(0,i,board,visited);
            if(board[m-1][i]=='O' && !visited[m-1][i])
                dfs(m-1,i,board,visited);
        }
        
        for(int i = 0; i<m ;i++)
        {
            if(board[i][0]=='O' && !visited[i][0])
                dfs(i,0,board,visited);
            if(board[i][n-1]=='O' && !visited[i][n-1])
                dfs(i,n-1,board,visited);
        }
        
        for(int i = 0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j]==false && board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
};