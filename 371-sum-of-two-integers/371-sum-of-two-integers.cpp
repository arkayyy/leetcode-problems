class Solution {
public:
    //INTUITION: We make sure the first bit (sign bit) of carry (a & b) always be zero to avoid the left shift of negative value error.
    int getSum(int a, int b) {
        while(a){
        int sum = a ^ b;
        a = ((a & b) & 0x7fffffff) << 1;
        b = sum;
        }
        return b;
    }
};