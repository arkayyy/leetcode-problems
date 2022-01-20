class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        
        while(n)
        {
            if(n&1) res = (n>0)?(res*x):(res*(1/x));
            x = x*x;
            n = n/2;
        }
        
        return res;
    }
};