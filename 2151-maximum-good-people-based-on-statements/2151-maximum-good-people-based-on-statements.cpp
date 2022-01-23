class Solution {
public:
    bool isValid(vector<int>& curr, vector<vector<int>> & statements)
    {
        for(int i = 0; i<curr.size(); i++)
            if(curr[i]==1)
                for(int j = 0; j<curr.size(); j++)
                    if(statements[i][j]!=2 && statements[i][j]!=curr[j])
                        return false;
        return true;
    }
    void dfs(int idx, int cnt, vector<int>& curr, int &ans, vector<vector<int>>& statements)
    {
        if(idx==statements.size())
        {
            if(isValid(curr,statements)) ans = max(ans,cnt);
            return;
        }
        
        curr.push_back(0); //if current person is marked bad
        dfs(idx+1, cnt, curr, ans, statements);
        curr.pop_back();
        curr.push_back(1); //if current person is marked good
        dfs(idx+1,cnt+1, curr, ans, statements);
        curr.pop_back();
    }
    int maximumGood(vector<vector<int>>& statements) {
        vector<int> curr;
        int ans = INT_MIN;
        dfs(0,0,curr,ans,statements);
        return ans;
    }
};