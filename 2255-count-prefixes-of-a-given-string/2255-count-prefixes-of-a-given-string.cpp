class Solution {
public:
    bool isPrefix(string s, string sub)
    {
        if(sub.length()>s.length()) return false;
        int i = 0;
        while(i<sub.length())
     {       if(s[i]!=sub[i])
                return false;
            ++i;}
        return true;
    }
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for(auto w: words)
            if(isPrefix(s,w))
                cnt++;
        return cnt;
    }
};