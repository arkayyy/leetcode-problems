class Solution {
public:
    //INTUITION: Simple Recursive Logic
    
    string util(string& s, int& idx)
    {
        string res = "";
        while(idx<s.length() && s[idx]!=']')
        {
            if(!isdigit(s[idx]))
                {res+=s[idx]; ++idx;}
            else
            {
                int n = 0;
                while(idx<s.length() && isdigit(s[idx]))
                    {n = n*10 + (s[idx]-'0'); ++idx;} //storing the number/frequency in n
                ++idx; //for skipping '['
                string temp = util(s,idx); //temp contains the result for in between the brackets
                ++idx; // for skipping ']'
                
                while(n--)
                    res+=temp;
            }
        }
        return res;
    }
    string decodeString(string s) {
        int idx = 0;
        return util(s,idx);
    }
};