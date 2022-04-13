class Solution {
public:
    //INTUITION: We have to count for all multiples of 5 and all multiples of the powers of 5 too. Because those will produce one zero each.
    //e.g. 5's multiples will produce one zero each. 5*5 (25's) multiples will produce additional one zeros each because of the extra 5.
    int trailingZeroes(int n) {
        // if(n==0) return 0;
        // return n/5 + trailingZeroes(n/5);
        int ans = 0;
        for(int i = 5; (n/i)>0; i*=5)
            ans += (n/i);
        return ans;
    }
};