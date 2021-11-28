class Solution {
public:
    int cnt=0;
    int decodeUtil(string s,int i, vector<int> &dp)
    {
        
        if(i>=s.length()) {  cnt++;
            return 1;}
        
        if(s[i]=='0') return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int ways = 0;
    
        ways +=  decodeUtil(s,i+1,dp);
        
        if(i+1<s.length() && ((s[i]-'0')*10)+(s[i+1]-'0')>=1 &&  ((s[i]-'0')*10)+(s[i+1]-'0')<= 26)
           ways += decodeUtil(s,i+2,dp);
              
        return dp[i] = ways;
    }
    
    int numDecodings(string s) {
       
        vector<int> dp (s.size()+1, -1);

        return decodeUtil(s,0,dp);
    }
    
};