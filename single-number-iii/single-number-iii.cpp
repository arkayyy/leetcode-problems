class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int xorsum = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            xorsum = xorsum ^ nums[i];
        } //finally xorsum after xorring all numbers, will have the xor of two numbers that appear only once in the array. All twice appearing numbers xor will get cancelled.
        
        int mask = xorsum & (~(xorsum-1));  //a binary number with all 0's except 1 at the position where xorsum had its rightmost set bit.

        int xor1 = 0,xor2 = 0;
    
        for(auto i:nums)
        {
            if(mask&i)   //the numbers which have that position as set bit too will go to one group (suppose one group will contain 3)
                xor1 ^= i;  
            else //the numbers which have that position as non-set bit too will go to another group (another will contain 5)
                xor2 ^= i;
        }//this is happening because we are using the concept that for x^y, the bit at the position of the rightmost set bit of x^y will be different for both x and y, that is why at that position their xor has a 1.

        return {xor1,xor2};
        
        
        
    }
};