class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int xorsum = 0;
        
        for(auto ch: s)
            xorsum = xorsum^(ch-'a');
        for(auto ch: t)
            xorsum = xorsum^(ch-'a');
        
        return (char)(xorsum+'a');
    }
};