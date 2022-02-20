class Solution {
public:
    string reformat(string s) {
        //------------------------MOST OPTIMAL APPROACH O(N) time-----------------------------//
        int digits = 0, chars = 0; 
        for(auto ch: s)
            isdigit(ch)?digits++:chars++;
        if(abs(digits-chars)>1) return "";
        
        string ans = "";
        int i = 0, j = 0;
        while(ans.length() < s.length())
        {
            if((ans.size()%2) ^ (digits > chars)) //MAIN LINE: we do this in order to decide which one alphabet or digit will be added first in the result string...when no. of digits is more, we have to start with a digit..same for number of alphabets
                //also the ans.size() checking even or odd always helps to place alphabets and digits in alternating sequence
            {
                while(isalpha(s[j])) j++; 
                ans+= s[j++];
            }
            else
            {
                while(isdigit(s[i])) i++;
                ans+=s[i++];
            }
        }
        return ans;
    }
};