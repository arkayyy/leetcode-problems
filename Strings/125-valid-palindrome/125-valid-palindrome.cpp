class Solution {
public:
    bool isPalindrome(string s) {
        
        string str="";
        for(auto ch: s)
        {
            if(ch-'a'>=0 && ch-'a'<26)
                str+=ch;                
            else if(ch-'A'>=0 && ch-'A'<26)
                str+=(char)(((int)ch) + 32);
            else if(ch-'0'>=0 && ch-'0'<=9)
                str+=ch;
        }
        

        int lo=0,hi=str.size()-1;
        while(lo<=hi)
        {
            if(str[lo]!=str[hi])
                return false;
            lo++,hi--;
        }
        return true;
    }
};