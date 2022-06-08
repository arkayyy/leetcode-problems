class Solution {
public:
    //INTUITION: Only if the given string is palindrome, we can remove the whole string at once to make it empty.
    //Otherwise, we can remove all a's in one go, and all b's in second move. DONE in 2 steps.
    bool isPalin(string& s)
    {
        int i = 0, j = s.size()-1;
        while(j>=i)
            {if(s[i]!=s[j]) return false;
            ++i,--j;}
        return true;
    }
    int removePalindromeSub(string s) {
        return 2-isPalin(s);
    }
};