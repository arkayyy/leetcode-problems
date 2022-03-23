class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s.length()>t.length())
            return false;
        
        int i = 0;
        int j = 0;
        
        while(i<s.length() && j<t.length())
        {
            while(j<t.length() && t[j]!=s[i])
                j++;
            
            if(j==t.length())
                break;
            
            i++,j++;
        }
        
        return i==s.length();
    }
};