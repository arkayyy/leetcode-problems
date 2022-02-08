class Solution {
public:
    int addDigits(int num) {
        if(num<10) return num;
        
        //To find the root digit of a number using congruance formula : 1+(num-1)%(base-1)
        return 1+(num-1)%(10-1);
    }
};