class Solution {
public:
    bool isPalin(string s)
    {
        int lo = 0, hi = s.size()-1;
        while(lo<=hi)
        {
            if(s[lo]!=s[hi])
                return false;
            lo++,hi--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        if(isPalin(s)) return true;
        
        int lo = 0, hi = s.size()-1;
        while(lo<=hi)
        {
            if(s[lo]!=s[hi])
                break;
            lo++,hi--;
        }
        string s1 = s.substr(0,lo) + s.substr(lo+1,s.size()-1-lo);
        string s2 = s.substr(0,hi) + s.substr(hi+1,s.size()-1-hi);
        
        if(isPalin(s1) || isPalin(s2)) return true;
        
        return false;
        
    }
};