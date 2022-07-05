class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26]{0};
        int start = 0, currSubstrMaxFreq = 0;
        for(int end = 0; end<s.size(); ++end)
        {
            currSubstrMaxFreq = max(currSubstrMaxFreq, ++freq[s[end]-'A']);
            int currSubstrLen = end-start+1;
            if(currSubstrLen - currSubstrMaxFreq > k) --freq[s[start++]-'A'];
        }
        return s.size()-start;
    }
};