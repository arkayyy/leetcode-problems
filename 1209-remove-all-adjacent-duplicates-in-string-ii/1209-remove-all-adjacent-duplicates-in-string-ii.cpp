class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        //============================APPROACH 1: Stack based frequency counting O(2N) Time O(N) Space===================//
        stack<pair<char,int>> st;
        for(auto c: s)
        {
            if(st.empty()) st.push({c,1});
            else if(c==st.top().first) {
                int freq = st.top().second;
                if(freq==k-1)
                {
                    for(int i = 0; i<freq; i++) st.pop();
                }
                else
                    st.push({c,freq+1});
            }
            else st.push({c,1});
        }
        
        string ans = "";
        while(!st.empty()) {ans+=st.top().first; st.pop();}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};