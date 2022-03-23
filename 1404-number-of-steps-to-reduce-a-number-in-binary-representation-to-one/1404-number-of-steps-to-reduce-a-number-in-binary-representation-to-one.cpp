class Solution {
public:
    int numSteps(string s) {
        //INTUITION: 
        //(i)If last digit is 1, number is odd, so add 2 steps (add 1 and divide by 2)
        //(ii) If last digit is 0, number is even, so add 1 step (divide by 2)
        
        //Now, dividing by 2 means number>>1 (right shift by 1 bit) (i.e. 1001 >> 1 = 0100, 0100 >> 1 = 0010)
        //This means we add one 0 to the left of the binary string. So nothing is needed to do anymore since only zeros will be adding from the left.
        //So now if we traverse the whole string, for every encountered 1, we add two steps, and for every encountered 0, we add one step
        
        //Now, adding 1 to the number might produce a carry, so we handle that too.
        
        int steps = 0, carry = 0;
        for(int i = s.length()-1; i>0; i--) // we traverse from the end, since addition occurs from the right to left
        {
            if((s[i]=='0' && carry==1) || (s[i]=='1' && carry == 0))  // or if sum(s[i]-'0'+carry) == 1 (i.e. encountered a 1)
            {
                steps+=2;
                carry = 1;
            }
            else  //encountered 0
                ++steps;
        }
        
        return steps+carry; //if carry is still present
    }
};