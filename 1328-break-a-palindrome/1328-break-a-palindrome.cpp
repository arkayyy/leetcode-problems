class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1) return "";
       int i;
        for(i = 0; i<palindrome.size()/2; ++i)
            if(palindrome[i]>'a')
            {palindrome[i] = 'a'; return palindrome;}
        // if(palindrome.size()%2==1 && i==)
        palindrome[palindrome.size()-1] += 1;
        return palindrome;
    }
};