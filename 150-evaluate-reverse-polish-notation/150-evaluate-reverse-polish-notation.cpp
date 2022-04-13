class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto t: tokens)
        {   //NOTE: We need to handle the case for negative nos. too
            if(isdigit(t[0]) || (t.length()>1 && isdigit(t[1])))
            {   
                int temp = 0;
                for(int i = (t[0]=='-'?1:0) ; i<t.length(); i++) 
                    temp = (temp*10)+(t[i]-'0');
                st.push(t[0]=='-'?(0-temp):temp);
            }
            else
            {
                int o1 = st.top(); st.pop();
                int o2 = st.top(); st.pop();
                int res;
                if(t=="+") res = o2+o1;
                else if(t=="-") res = o2-o1;
                else if(t=="*") res = o2*o1;
                else res = o2/o1;
                st.push(res);
            }
        }
        return st.top();
    }
};