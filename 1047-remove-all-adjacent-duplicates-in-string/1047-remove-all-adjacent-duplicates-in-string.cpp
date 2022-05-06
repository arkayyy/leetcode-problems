class Solution {
public:
    
    string removeDuplicates(string s) {
        //==================================APPROACH 1: Stack Based O(2N) Time O(N) Space==============================// 
        // stack<char> st;
        // for(auto ch:s)
        // {
        //     if(st.empty()) st.push(ch);
        //     else if(st.top()==ch) st.pop();
        //     else st.push(ch);
        // }
        // string ans = "";
        // while(!st.empty()) {ans+=st.top(); st.pop();}
        // reverse(ans.begin(),ans.end());
        // return ans;
        
        //================================APPROACH 2: Two Pointer O(N) Time O(1) Space=================================///
        string t = s;
        int i = 0, j = 0; //remember that i index will be at a position such that from 0 to i there will be no repitition of any letter
        while(j<s.length())
        {
            t[i] = t[j]; //we kind of eliminate all the repeating letters in between i and j index
            if(i>0 && t[i-1]==t[i])  //checking for two adjacent characters
                i-=2;
            ++i,++j;
        }
        return t.substr(0,i); 
    }
};