class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string ans = "";
        
        bool carry = false;
        
        string a1,b1;
        if(a.length()>b.length()) {a1=a; b1=b;}
        else {a1=b; b1=a;}
        
        for(int i = 0; i<b1.length();i++)
        {
            if(b1[i]=='0')
            {
                if(a1[i]=='1') { 
                    if(carry) ans+='0';
                    else ans+='1';
                }
                else { 
                    if(carry){ ans+='1'; carry=false;}
                    else ans+='0';
                }
            }
            else
            {
                if(a1[i]=='1')
                {
                    if(carry) ans+='1';
                    else {ans+='0'; carry=true;}
                }
                else
                {
                    if(carry) ans+='0';
                    else {ans+='1';}
                }
            }
        }
        
        for(int i=b1.length();i<a1.length();i++)
        {
            if(a1[i]=='0') {
                if(carry){ans+='1'; carry=false;}
                else ans+='0';
            }
            else
            {
                if(carry) ans+='0';
                else {ans+='1'; }
            }
        }
        
        if(carry)
            ans+='1';
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
        
    }
};