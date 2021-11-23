class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
         unsigned rev = 0;
        
        for(int i=0;i<31;i++)
        {
            rev += n & 1;  //adding 0 if last bit of n is 0 or else 1
            n = n>>1; //eliminating one 1 from last of n
            rev = rev<<1; //shifting 1 from starting of rev
        }
        
        rev += n & 1; //adding the last 0 or 1
        return rev;    //reversed number
    }
};