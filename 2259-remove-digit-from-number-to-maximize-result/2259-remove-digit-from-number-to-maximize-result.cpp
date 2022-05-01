class Solution {
public:
    //INTUITION: We can do 2things:-
    //(i) We can get the leftmost appearance of digit in number where it is followed by a greater digit on its right, in order to get a lexicographically larger number
    //(ii) or if no such appearance exists, we need to remove the rightmost appearance of the digit to get the lexicographically largest number
    string removeDigit(string number, char digit) {
        bool flag = true;
        int findex=-1; //denotes first occurence of digit from right end of number
        int idx = -1; //the leftmost occurence of digit where digit is followed by a greater digit on its right
        for(int i = number.size()-1; i>=0; i--)
        {
            if(number[i]==digit)
            {
                if(flag)
                {flag = false; findex = i;}
                if(number[i]-number[min((int)number.size()-1,i+1)] < 0)
                    idx = i;
            }
        }
        if(idx==-1) {number.erase(findex,1);}
        else number.erase(idx,1);
        
        return number;
    }
};