class Solution {
public:
    int maxVowels(string s, int k) {
        // vector<int> pre(s.size(),0);
        // pre[0] =(s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u');
        // int ans = 0;
        // for(int i = 1; i<s.size(); i++)
        //     cout<<(pre[i] = pre[i-1]+(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'))<<" ";
        // for(int i = 0; i+k-1<s.size(); i++)
        // {//cout<<(i)<<" to "<<(i+k-1)<<endl;
        //     ans = max(ans, pre[i+k-1] - (i-1<0?0:pre[i-1]));}
        // return ans;
        
        int cnt = 0;
        for(int i = 0; i<k; i++) cnt+=(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u');
        int ans = cnt;
        for(int i = k; i<s.size(); i++)
        {
            cnt-=(s[i-k]=='a'||s[i-k]=='e'||s[i-k]=='i'||s[i-k]=='o'||s[i-k]=='u');
            cnt+=(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u');
            ans = max(ans,cnt);
        }
        return ans;
    }
};