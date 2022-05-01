class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int backspaces = 0, i = s.length()-1, j = t.length()-1;
        while(1>0)
        {
            //decreasing pointer of s string as per the backspace(#) occurence
            backspaces = 0;
            while(i>=0 && (backspaces>0 || s[i]=='#')) { backspaces += s[i]=='#'?1:-1; --i;}
            //decreasing pointer of t string as per the backspace(#) occurence
            backspaces = 0;
            while(j>=0 && (backspaces>0 || t[j]=='#')) { backspaces += t[j]=='#'?1:-1; --j;}
            //checking if the current index character in both strings are same
            if(i>=0 && j>=0 && s[i]==t[j])
                --i,--j;
            else break;
        }
        return i==-1&&j==-1; //if both strings have been exhausted while checking only then we can say they are equally typed
    }
};