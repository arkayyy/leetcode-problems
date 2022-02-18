class Solution {
public:
    string reformat(string s) {
        stack<int> digits; //frequency of digits from 0-9
        stack<char> chars;
        for(auto ch:s)
        {
            if(ch-'a'>=0 && ch-'a'<26) chars.push(ch);
            else digits.push(ch-'0');
        }
        
        if( abs((int)digits.size()-(int)chars.size()) > 1) return "";
        
        string ans = "";
        if(digits.size() > chars.size())
        {
            while(!digits.empty() && !chars.empty())
            {
                ans+=to_string(digits.top()); digits.pop();
                ans+=chars.top(); chars.pop();
            }
            if(!digits.empty())
            ans+=to_string(digits.top());
        }
        else
        {
            while(!digits.empty() && !chars.empty())
            {
                ans+=chars.top(); chars.pop();
                ans+=to_string(digits.top()); digits.pop();
            }
            if(!chars.empty())
            ans+=chars.top();
        }
        
        return ans;
    }
};