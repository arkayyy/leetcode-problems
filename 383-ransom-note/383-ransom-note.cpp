class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(256,0);
        for(auto&c:magazine) ++freq[c];
        for(auto&c:ransomNote)
        {
            if(!freq[c]) return false;
            --freq[c];
        }
        return true;
    }
};