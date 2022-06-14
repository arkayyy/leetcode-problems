class Solution {
public:
    int util(int i, int j, string& s, int k)
    {
        if(i>j || k>j-i+1) return 0; //if k exceeds the length of substring no use of counting and checking, its impossible for any char to have freq>=k
        vector<int> cnt(26,0);
        for(int t = i; t<=j; ++t) ++cnt[s[t]-'a'];
        for(int t= i; t<=j; ++t) 
            if(cnt[s[t]-'a']<k) //first violation found (freq < k). So the ans substring must lie in either left or right half of this index
                return max(util(i,t-1,s,k),util(t+1,j,s,k));
        return j-i+1; //no violation found, valid substring as per criteria
    }
    int longestSubstring(string s, int k) {
        return util(0,s.size()-1,s,k);
    }
};