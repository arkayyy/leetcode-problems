class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        string ans = "";
        bool sw = true;
        while(i<word1.length() && j<word2.length())
        {
            if(sw)
            {
                ans+=word1[i];
                ++i;
            }
            else
            {
                ans+=word2[j];
                ++j;
            }
            sw = !sw;
        }
        if(i<word1.length())
            ans+=word1.substr(i,word1.length()-i);
        if(j<word2.length())
            ans+=word2.substr(j,word2.length()-j);
        
        return ans;
    }
};