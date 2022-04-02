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
        if(isPalin(s)) return true; //if already palindrome no need to do any change and check
        
        int lo = 0, hi = s.size()-1;
        while(lo<=hi)
        {
            if(s[lo]!=s[hi]) //continuing until we find a dissimilar pair of characters
                break;
            lo++,hi--;
        }
        string s1 = s.substr(0,lo) + s.substr(lo+1,s.size()-1-lo); //removing the character at 1st pointer index
        string s2 = s.substr(0,hi) + s.substr(hi+1,s.size()-1-hi); //removing the character at 2nd pointer index
        
        if(isPalin(s1) || isPalin(s2)) return true; //if after removing either of them we get a palindrome we return true as per the question
        
        return false; //if dissimalirity still remains
        
    }
};