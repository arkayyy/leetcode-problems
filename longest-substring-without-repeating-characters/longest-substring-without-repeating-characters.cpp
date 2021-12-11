class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.length()==0) return 0;
        
        vector<int> freq(256,0);
        
        int l = 0, r = 0;
        int maxLen = INT_MIN;
        while(r<s.length())
        {
            freq[s[r]]++;
            
            while(freq[s[r]]>1)
            {
                freq[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        
        return maxLen;
    }
};