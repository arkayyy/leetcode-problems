class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size()-1; i>=0; i--)
        {
            int t = digits[i]+carry;
            if(t>=10)
            {
                digits[i] = t%10;
            }
            else
            {
                digits[i] = t;
                carry = 0;
                break;
            }
        }
        
        if(carry) //will happen only in the case of 
            {digits.push_back(0);  digits[0]=1;}  
        
        return digits;
    }
};