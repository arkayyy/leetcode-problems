class Solution {
public:
    string addBinary(string a, string b) {
        
        int m = a.length(),n = b.length();
        string p="",q="";
   
        //we will store the bigger string in p and smnaller in q for easy and hassle-free traversal. m will have bigger string length and n will contain smaller string length
        if(m>n)
        {p = a; q = b; } 
        else
        {p=b; q=a;  m = m^n; n=m^n; m=m^n;}
        
        reverse(p.begin(),p.end()); reverse(q.begin(),q.end()); //reversing both input strings because addition of any two numbers always happens from their end side
        int i = 0;
        int carry = 0;
        
        string ans="";
        while(i<n) //setting limit of traversal till the smaller binary string first
        {
            if(p[i]=='0' && q[i]=='0') //both bits are 0
                { 
                    ans+=(char)(carry+'0'); carry = 0;
                }
            else if((p[i]=='1' && q[i]=='0')||(p[i]=='0' && q[i]=='1')) //different bits
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
            else //if p[i]==1 and q[i]==1  //both bits are 1
            {
                if(!carry){
                    ans += '0'; carry = 1;
                }
                else
                    ans+='1';
            }
            i++;
        }
        
        while(i<m) // if the whole of the bigger binary number has not been yet traversed
        {
            if(p[i]=='0')
            {
                if(carry){ans+='1'; carry=0;}
                else{ans+='0'; }
            }
            else //if(p[i]=='1')
            {
                if(carry){ans+='0';}
                else{ans+='1'; carry = 0;}
            }
            i++;
        }
        
        if(carry) //if a carry bit is still left, adding it
            ans+='1';
        
        reverse(ans.begin(),ans.end()); //reversing the sum to get the final answer(since we used reversed input strings at tht beginning)

        return ans;
        
    }
};