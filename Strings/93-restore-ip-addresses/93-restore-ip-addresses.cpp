class Solution {
public:
    void util(int idx, int parts , string curr, string s, vector<string>&ans)
    {
        if(idx>=s.length()) {
        if(parts==4)
            ans.push_back(curr.substr(0,curr.size()-1)); //using substr to remove dot from last
        return;}
        
        int d1,d2,d3;
        d1 = s[idx]-'0';
        util(idx+1, parts+1, curr+to_string(d1)+".", s, ans); 
        
        if(idx+1<s.size() && s[idx]!='0') //will not take leading zeros
        {
            d2 = ((s[idx]-'0')*10) + (s[idx+1]-'0'); //two digit number will always be below 256
            util(idx+2,parts+1,curr+to_string(d2)+".", s, ans);
        }
            
        if(idx+2<s.size() && s[idx]!='0') //will not take leading zeros
        {
            d3 = ((s[idx]-'0')*100) + ((s[idx+1]-'0')*10) + (s[idx+2]-'0');
            if(d3<256)
            util(idx+3,parts+1,curr+to_string(d3)+".", s, ans);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        util(0,0,"",s,ans);
        return ans;
    }
};