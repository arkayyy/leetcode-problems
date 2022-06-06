class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2==1) return false;
        
        int unpaired = 0, unlocked = 0, open = 0, closed = 0;
        for(int i = 0; i<s.size(); ++i)
        {
            if(locked[i]=='0') ++unlocked;
            else if(s[i]=='(') ++open;
            else if(s[i]==')') ++closed;
            unpaired = closed-open; //because while going from left to right, open brackets come first and then closed brackets, so unpaired brackets would be caused by closing brackets
            if(unpaired>unlocked) return false;
        }
        
        unpaired = 0, unlocked = 0, open = 0, closed = 0;
        for(int i = s.size()-1; i>=0; --i)
        {
            if(locked[i]=='0') ++unlocked;
            else if(s[i]=='(') ++open;
            else if(s[i]==')') ++closed;
            unpaired = open-closed;//because while going from right to left, close brackets come first and then open brackets, so unpaired brackets would be caused by opening brackets
            if(unpaired>unlocked) return false;
        }
        return true;
    }
};