class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int> pre(s.size(),0);
        pre[0] =(s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u');
        int ans = INT_MIN;
        for(int i = 1; i<s.size(); i++)
            cout<<(pre[i] = pre[i-1]+(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'))<<" ";
        for(int i = 0; i+k-1<s.size(); i++)
        {//cout<<(i)<<" to "<<(i+k-1)<<endl;
            ans = max(ans, pre[i+k-1] - (i-1<0?0:pre[i-1]));}
        return ans;
    }
};