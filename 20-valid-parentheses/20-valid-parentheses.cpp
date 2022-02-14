class Solution {
public:
    bool isValid(string s) {
        
        int nopen=0,nclose=0;
        
        unordered_map<char,char> mp;
        
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';
        
        stack<char> st;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' )
                nopen++;
            if(s[i]==')' || s[i]=='}' || s[i]==']' )
                nclose++;
        }
        
        if(nopen!=nclose)
            return false;
        
        for(int i = 0; i<s.length();i++)
        {
            if(!st.empty() && st.top()==mp[s[i]])
                st.pop();
            else
                st.push(s[i]);
        }
        
       if(st.empty())
           return true;
        return false;
    }
};