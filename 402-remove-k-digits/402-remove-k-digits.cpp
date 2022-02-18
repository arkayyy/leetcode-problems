class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(auto d: num)
        {
            while(!st.empty() && d<st.top() && k)
                {st.pop(); k--;}
            if(st.size()) st.push(d);
            else if(d!=0) st.push(d);
        }
        while(k-->0)
            st.pop();
        string ans = "";

        while(!st.empty())
        {
            ans = to_string(st.top()-'0')+ ans;
            st.pop();
        }
        
        if(ans=="") return "0";

        int i = 0; while(i<ans.length() && ans[i]=='0') i++;                    
        return i==ans.length()?"0" : ans.substr(i,ans.size()-i+1);
    }
};