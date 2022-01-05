class Solution {
public:
    bool isPalin(string s)
    {
        int l = 0, r = s.length()-1;
        while(l<=r)
        {
            if(s[l]!=s[r])
                return false;
            l++,r--;
        }
        return true;
    }
    void util(int idx, string &s,  vector<string>& curr, vector<vector<string>>& ans)
    {
        if(idx==s.size())
        {
            //if it reaches the end of the string, then pushing to the final answer vector
            ans.push_back(curr);
            return;
        }
        
        for(int i = idx; i< s.length(); i++ )
        {
            if(isPalin(s.substr(idx,i-idx+1)))
            {
                //if its palindrome pushing it into the current combination
                curr.push_back(s.substr(idx,i-idx+1));
                
                util(i+1, s, curr, ans);
                //popping it from the current combination after it has been added to the final vector
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        
        if(s=="") return ans;
        
        util(0,s,curr, ans);
        
        return ans;
    }
};