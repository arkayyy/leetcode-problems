class Solution {
    //Similar question: https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/
public:
    //INTUTITION: We do 2 traversals in total:-
    //(i) left to right: if the number of closed brackets exceed the opening brackets then the stars need to act as the leftover opening brackets needed
    //(ii) right to left: if the number of opening brackets exceed the closing brackets then the stars need to act as the leftover closing brackets needed
    //So in both traversals, at any time if the number of unpaired brakcets exceeds the numbmer of stars available to cover them up, we can't make the string valid in any way.
    bool checkValidString(string s) {
        int unpaired = 0, stars = 0, open = 0, closed = 0;
        for(int i = 0; i<s.size(); ++i)
        {
            if(s[i]=='*') ++stars;
            else if(s[i]=='(') ++open;
            else if(s[i]==')') ++closed;
            
            unpaired = closed-open;//because while going from left to right, open brackets come first and then closed brackets, so unpaired brackets would be caused by closing brackets
            if(unpaired>stars) return false;
        }
        
        unpaired = 0, stars = 0, open = 0, closed = 0;
        for(int i = s.size()-1; i>=0; --i)
        {
            if(s[i]=='*') ++stars;
            else if(s[i]=='(') ++open;
            else if(s[i]==')') ++closed;
            unpaired = open-closed;//because while going from right to left, close brackets come first and then open brackets, so unpaired brackets would be caused by opening brackets
            if(unpaired>stars) return false;
        }
        return true;
    }
};