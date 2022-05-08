class Solution {
public:
    //INTUITION: Binary Exponentiation...
    double myPow(double x, int n) {
        //Iterative:-
        // double res = 1;
        // while(n)
        // {
        //     if(n&1) res = n<0?(res*(1/x)):(res*x);
        //     x = x*x;
        //     n = (n>>1);
        // }
        // return res;
        
        //Recursive:-
        if(n<0) return (1/x)*myPow(1/x,-(n+1)); //extra case for negative powers
        if(n==0) return 1;
        if(n&1) return x* myPow(x*x, (n>>1));
        return myPow(x*x, (n>>1));
    }
};