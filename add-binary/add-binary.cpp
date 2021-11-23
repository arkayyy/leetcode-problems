class Solution {
public:
    string addBinary(string a, string b) {
        
        int m = a.length(),n = b.length();
        string p="",q="";
        if(m>n)
        {p = a; q = b; }
        else
        {p=b; q=a;  m = m^n; n=m^n; m=m^n;}
        
        reverse(p.begin(),p.end()); reverse(q.begin(),q.end());
        int i = 0;
        int carry = 0;
        
        string ans="";
        while(i<n)
        {
            if(p[i]=='0' && q[i]=='0')
                { 
                    ans+=(char)(carry+'0'); carry = 0;
                }
            else if((p[i]=='1' && q[i]=='0')||(p[i]=='0' && q[i]=='1'))
            {
                if(carry)
                {
                    ans+='0';
                }
                else
                {
                    ans+='1';
                }
            }
            else //if p[i]==1 and q[i]==1
            {
                if(!carry){
                    ans += '0'; carry = 1;
                }
                else
                    ans+='1';
            }
            i++;
        }
        
        while(i<m)
        {
            if(p[i]=='0')
            {
                if(carry){ans+='1'; carry=0;}
                else{ans+='0'; }
            }
            else //if(a[i]=='1')
            {
                if(carry){ans+='0';}
                else{ans+='1'; carry = 0;}
            }
            i++;
        }
        
        if(carry)
            ans+='1';
        
        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};