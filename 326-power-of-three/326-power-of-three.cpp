class Solution {
public:
    bool isPowerOfThree(int n) { 
        if(n<=0) return false;
        if(n==1) return true;
        //INTUITION: If we consider the highest power of 3 that fits the integer data type range, any lesser or equal power of 3 would surely be able to divide it.
        int maxPowerOf3FitsInt = 1162261467;
        return (maxPowerOf3FitsInt%n == 0);
    }
};