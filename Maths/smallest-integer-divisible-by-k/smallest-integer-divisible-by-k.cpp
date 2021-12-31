class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if((k&1)==0 || k%5==0)
            return -1;
        int len = 1;
        int num = 1;
        while(num%k!=0)
        {
            //normally we think of num = num*10 + 1; and then we are checking if num%k==0
            //But by applying modular arithmetic, we know that it can be rewritten as num%k = ((nums*10)%k + (1%k))%k
            num = (((num*10)%k) +( 1%k));
            len++;
        }
        return len;
    } 
};