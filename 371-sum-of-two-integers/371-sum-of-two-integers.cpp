class Solution {
public:
    //INTUITION: We make sure the first bit (sign bit) of carry (a & b) always be zero to avoid the left shift of negative value error.
    int getSum(int a, int b) {
        while(a){
        int sum = a ^ b; //sum of a and b without the carry
        a = ((a & b) & 0x7fffffff) << 1; //calculating the carry
        b = sum; //adding sum without carry and the carry
        }
        return b;
    }
};