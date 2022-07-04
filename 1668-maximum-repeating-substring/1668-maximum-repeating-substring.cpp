class Solution {
public:
    void fillLps(string word, vector<int>& lps)
    {
        int len = 0, i = 1;
        lps[0] =0;
        while(i<word.size())
        {
            if(word[i]==word[len])
            {
                ++len;
                lps[i] = len;
                ++i;
            }
            else
            {
                if(len!=0)
                    len = lps[len-1];
                else
                {lps[i] = 0; ++i;}
            }
        }
    }
    
    int kmp(string &sequence, string& word)
    {
        vector<int> lps(word.size(),0);
        fillLps(word,lps);
        int i = 0, j = 0, ans = 0;
        while(i<sequence.size() && j<word.size())
        {
            if(sequence[i]==word[j])
                ++i,++j;

            else //if(i<sequence.size() && sequence[i]!=word[j])
            {
                if(j!=0) j = lps[j-1];
                else ++i;
            }
        }
        if(j==word.size())
             ans+=1;
        
        return ans;
    }
    int maxRepeating(string sequence, string word) {
        
        int k = 0;
        string pattern = word;
        while(true)
        {
            int res = kmp(sequence,pattern);
            if(res==0) break;
            ++k, pattern+=word;
        }
        return k;
    }
};