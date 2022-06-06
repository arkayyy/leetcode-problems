class Solution {
public:
    bool isValid(string s) {
        
        unordered_map<char,char> mp;
        
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';
        
        stack<char> st;
    
        
        for(int i = 0; i<s.length();i++)
        {
            if(!st.empty() && st.top()==mp[s[i]]) st.pop();
            else st.push(s[i]);
        }
        
       return st.empty();
    }
};