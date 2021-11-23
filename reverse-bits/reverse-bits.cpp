class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int num = 0;
        
        for(int i =0;i<32;i++)
        {
            if((n&(1<<(31-i)))) // doing (31-i) to check every bit that is ith position from the end of the given number and if it is set
                num = (1<<i)|num;  //setting that bit set ith position from the starting of the answer(initially taken as 0)
        }
        
        return num;
    }
};