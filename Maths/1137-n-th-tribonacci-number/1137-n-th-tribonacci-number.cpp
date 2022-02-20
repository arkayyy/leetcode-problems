class Solution {
public:
    int tribonacci(int n) {
        if(n==0 || n==1) return n;
        if(n==2) return 1;
        
        int a = 0, b = 1, c = 1, d=a+b+c;
        while(n-->=3)
        {
            d = a+b+c;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
};