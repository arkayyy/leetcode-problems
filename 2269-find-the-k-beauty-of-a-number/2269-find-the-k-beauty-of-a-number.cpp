class Solution {
public:
    int numb(string s)
    {
        int res = 0;
        for(int i = 0; i<s.size(); i++)
            res = res*10 + (s[i]-'0');
        return res;
    }
    int divisorSubstrings(int num, int k) {
        
        int ans = 0;
        string s = to_string(num);
        for(int i = 0; i<s.length()-k+1; i++)
           { int t = numb(s.substr(i,k));
            if(!t) continue;
            if((num%t) == 0) ++ans;}
        return ans;
    }
};