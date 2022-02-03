class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(256,0); vector<bool> visited(256,false);
        for(auto ch: s) freq[ch]++;
        string res = "0";
        for(auto ch: s)
        {
            freq[ch]--;
            if(visited[ch]) continue;
            // ch < res.back() -> because we need the lexicographically least subsequence containing all unique letters in the string, so we keep popping until we get lexo least subsequence
            // freq[res.back()] > 0 -> because if freq[res.back()]==0 we know that no more of this character will occur next in the string, so we can't pop this, it's already part of lexo least subseq
            while(ch < res.back() && freq[res.back()]) {visited[res.back()] = false; res.pop_back();}
            res+=ch;
            visited[ch] = true;
        }
        return res.substr(1);
    }
};