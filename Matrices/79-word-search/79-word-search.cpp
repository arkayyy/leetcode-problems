class Solution {
public:
    bool util(string curr, int idx, string word, int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited)
    {
        if(idx>=word.length())
        {
            if(curr==word) return true;
            return false;
        }
        if(curr==word) return true;
        
        if(i+1<board.size() && board[i+1][j]==word[idx] && !visited[i+1][j])
        {
            visited[i+1][j] = true;
            if(util(curr+board[i+1][j],idx+1,word,i+1,j,board,visited))
                return true;
            visited[i+1][j] = false;
        }
        
        if(i-1>=0 && board[i-1][j]==word[idx] && !visited[i-1][j])
        {
            visited[i-1][j] = true;
            if(util(curr+board[i-1][j],idx+1,word,i-1,j,board,visited))
                return true;
            visited[i-1][j] = false;
        }
        
        if(j+1<board[0].size() && board[i][j+1]==word[idx] && !visited[i][j+1])
        {
            visited[i][j+1] = true;
            if(util(curr+board[i][j+1],idx+1,word,i,j+1,board,visited))
                return true;
            visited[i][j+1] = false;
        }
        
        if(j-1>=0 && board[i][j-1]==word[idx] && !visited[i][j-1])
        {
            visited[i][j-1] = true;
            if(util(curr+board[i][j-1],idx+1,word,i,j-1,board,visited))
                return true;
            visited[i][j-1] = false;
        }
        
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
       vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(),false));
        for(int i = 0; i<board.size(); i++)
        {
            for(int j = 0; j<board[0].size(); j++)
            {
                if(board[i][j]==word[0])
                {
                    string curr = "";
                    curr+=board[i][j];
                    visited[i][j] = true;
                    if(util(curr,1,word,i,j,board,visited))
                        return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};