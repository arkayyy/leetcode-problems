class Solution {
public:
    bool checkValidString(string s) {
        int unpaired = 0, stars = 0, open = 0, closed = 0;
        for(int i = 0; i<s.size(); ++i)
        {
            if(s[i]=='*') ++stars;
            else if(s[i]=='(') ++open;
            else if(s[i]==')') ++closed;
            
            unpaired = closed-open;
            if(unpaired>stars) return false;
        }
        
        unpaired = 0, stars = 0, open = 0, closed = 0;
        for(int i = s.size()-1; i>=0; --i)
        {
            if(s[i]=='*') ++stars;
            else if(s[i]=='(') ++open;
            else if(s[i]==')') ++closed;
            unpaired = open-closed;
            if(unpaired>stars) return false;
        }
        return true;
    }
};