class Solution {
public:
    string reverseParentheses(string s) {
        
        //----------------APPROACH - 1 : BRUTE FORCE O(N^2) ----------------------------------------------------//
        // vector<int> opened;
        // string ans;
        // for (int i = 0; i < s.length(); ++i) {
        //     if (s[i] == '(')
        //         opened.push_back(ans.length());
        //     else if (s[i] == ')') {
        //         int j = opened.back();
        //         opened.pop_back();
        //         reverse(ans.begin() + j, ans.end());
        //     } else {
        //         ans += s[i];
        //     }
        // }
        // return ans;
        
        
        //----------------------------------MOST OPTIMAL O(N) APPROACH - WORMHOLE (by lee)---------------------------//
        vector<int> pair(s.size());
        vector<int> opened;
        
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i]=='(')
                opened.push_back(i);
            if(s[i]==')') 
            {
                //creating the ends of the wormhole
                int j = opened.back();
                opened.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }
        
        int d = 1;
        string ans = "";
        for(int i = 0; i<s.size(); i+=d)
        {
            if(s[i]=='(' || s[i]==')') { d = -d; i = pair[i];}//travelling to other end of the wormhole (and inverting the direction of further movement)
            else
                ans+=s[i];
        }
        
        return ans;
        
    }
};