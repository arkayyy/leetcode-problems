class Solution {
public:
    int numSteps(string s) {
        //INTUITION: 
        //Dividing by 2 means number>>1 (right shift by 1 bit) (i.e. 1001 >> 1 = 0100, 0100 >> 1 = 0010)
        
        //ALGO: First we move from the right until we encounter a 1, and at every move we add 1 to steps. 
        //Because for all trailing zeros, we right shift(divide by 2) until we have no trailing zeros and we encounter 1.
        //Next, for every 0 encountered, we add 2 steps, and for every 1 encountered, we add 1 step.
        
        int steps = 0;
        
        int i = s.length()-1;
        while(i>=0 && s[i]=='0')
        {
            i--, steps++;
        }
        if(i==0)
            return steps;
        
        while(i>=0)
        {
            if(s[i]=='0')
            {
                steps+=2;
            }
            else
                ++steps;
            i--;
        }
        return steps+1; 
    }
};