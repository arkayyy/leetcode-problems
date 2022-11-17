class Solution {
public:
    bool checkString(string s) {
        int ca = 0, cb = 0;
        for(auto&c: s)
        {
            if(c=='a') {if(cb) return false; ++ca;}
            else if(c=='b') { ++cb;}
        }
        return true;
    }
};