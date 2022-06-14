class Solution {
public:
    int util(int i, int j, string& s, int k)
    {
        if(i>j || k>j-i+1) return 0;
        vector<int> cnt(26,0);
        for(int t = i; t<=j; ++t) ++cnt[s[t]-'a'];
        for(int t= i; t<=j; ++t) 
            if(cnt[s[t]-'a']<k)
                return max(util(i,t-1,s,k),util(t+1,j,s,k));
        return j-i+1;
    }
    int longestSubstring(string s, int k) {
        return util(0,s.size()-1,s,k);
    }
};