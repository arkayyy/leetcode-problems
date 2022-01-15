class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> pat;
        unordered_map<string,char> pat1;
        
        int wordCount = 0;
        int i = 0; //for pattern
        int j = 0; //for string
        while(i<pattern.length() && j<s.length())
        {
            string word="";
            while(j<s.length() && s[j]!=' ')
               { word+=s[j]; j++;}

            //cout<<word<<"->"<<pattern[i]<<endl;
            if(((pat.find(pattern[i])!=pat.end()) && pat[pattern[i]] != word) || (pat1.find(word)!=pat1.end() && pat1[word]!=pattern[i]))
                return false;
            pat[pattern[i]] = word;
            pat1[word] = pattern[i];
            i++,j++;
        }
        if(i<pattern.length() || j<s.length()) return false;
        return true;
    }
};