class Solution {
public:
    struct tnode
    {
        vector<tnode*>children;
        char ch;
        bool endOfWord = false;
        tnode(char c)
        {
            ch = c;
            children = vector<tnode*>(26,NULL);
        }
    };
    
    void insert(string s, tnode* root)
    {
        tnode* curr = root;
        for(int i = 0; i<s.size(); i++)
        {
            if(!curr->children[s[i]-'a'])
                curr->children[s[i]-'a'] = new tnode(s[i]);
            curr = curr->children[s[i]-'a'];
        }
        curr->endOfWord = true;
    }
    
    void search(int i, int j, string curr, tnode* root, vector<vector<char>>& board, vector<vector<bool>>& visited, unordered_set<string>& ans)
    {
        if(!root || board[i][j]!=root->ch)
            return;
        string temp = curr+root->ch;
        if(root->endOfWord) {ans.insert(temp);}
        
        if(i+1<board.size() && !visited[i+1][j] && root->children[board[i+1][j]-'a'])
        {
            visited[i+1][j] = true;
            search(i+1, j, temp, root->children[board[i+1][j]-'a'],board,visited,ans);
            visited[i+1][j] = false;
        }
        if(i-1>=0 && !visited[i-1][j] && root->children[board[i-1][j]-'a'])
        {
            visited[i-1][j] = true;
            search(i-1, j, temp, root->children[board[i-1][j]-'a'],board,visited,ans);
            visited[i-1][j] = false;
        }
        if(j+1<board[0].size() && !visited[i][j+1] && root->children[board[i][j+1]-'a'])
        {
            visited[i][j+1] = true;
            search(i, j+1, temp, root->children[board[i][j+1]-'a'],board,visited,ans);
            visited[i][j+1] = false;
        }
        if(j-1>=0 && !visited[i][j-1] && root->children[board[i][j-1]-'a'])
        {
            visited[i][j-1] = true;
            search(i, j-1, temp, root->children[board[i][j-1]-'a'],board,visited,ans);
            visited[i][j-1] = false;
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        tnode* root = new tnode('z');
        
        for(auto w: words)
            insert(w,root);
        unordered_set <string> ans;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i<board.size(); i++)
        {
            for(int j = 0; j<board[0].size(); j++)
            {
                if(root->children[board[i][j]-'a'])
                {
                    visited[i][j] = true;
                    search(i,j,"",root->children[board[i][j]-'a'],board,visited,ans);
                    visited[i][j] = false;
                }
            }
        }
        vector<string> res(ans.begin(), ans.end());
        return res;
    }
};