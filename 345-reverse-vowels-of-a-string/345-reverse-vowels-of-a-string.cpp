class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size()-1;
        unordered_set<char> vow({'a','e','i','o','u','A','E','I','O','U'});
        while(l<r)
        {
            while(l<r && vow.find(s[l])==vow.end())
                ++l;
            while(r>l && vow.find(s[r])==vow.end())
                --r;
            if(l<r) {swap(s[l],s[r]); ++l,--r;}
        }
        return s;
    }
};