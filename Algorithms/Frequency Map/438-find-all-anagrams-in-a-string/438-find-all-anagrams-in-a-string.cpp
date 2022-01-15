class Solution {
public:
    //ALGO: using the concept of equating frequency map of every p-length substring in s, with the frequency map of p
    vector<int> findAnagrams(string s, string p) {
        int plen = p.size();
        
        if(plen>s.size()) return {};
        
        vector<int> freqp(26,0);
        for(auto ch: p) freqp[ch-'a']++;
        
        vector<int> freqs(26,0);
        vector<int> ans;
        
        for(int i=0;i<p.length(); i++)
            freqs[s[i]-'a']++;
        
        if(freqs==freqp) ans.push_back(0);
        
        for(int i = 0; i+plen<s.length(); i++)
        {//Sliding window approach; window size = p.length()
            freqs[s[i]-'a']--; //eliminating one previous character
            freqs[s[i+plen]-'a']++;  //adding one character forward
            if(freqp==freqs)
                ans.push_back(i+1);
        }
        
        return ans;
    }
};