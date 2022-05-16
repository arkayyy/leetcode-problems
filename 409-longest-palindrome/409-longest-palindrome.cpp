class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> freq;
        for(auto ch:s) ++freq[ch];
        int ans = 0;
        bool odd = false;
        for(auto f: freq)
        {
            if((f.second&1)==0) ans+=f.second;
            else {odd = true; ans+=f.second - 1;}
        }
        return odd?ans+1:ans;
    }
};