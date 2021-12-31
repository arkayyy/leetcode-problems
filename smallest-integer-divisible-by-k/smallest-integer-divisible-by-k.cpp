class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if((k&1)==0 || k%5==0)
            return -1;
        int len = 1;
        int num = 1;
        while(num%k!=0)
        {
            num = ((num*10)%k) +( 1%k);
            len++;
        }
        return len;
    } 
};