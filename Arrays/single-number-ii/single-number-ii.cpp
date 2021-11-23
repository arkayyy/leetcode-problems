#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        //taking constant extra space vector, which will store the count of numbers in the given array for which the ith index bit is set.
        vector<int> binaryBits(32,0);
        
        for(int i = 0;i<32;i++)
        {
            for(auto j:nums)
            {
                if((j&(1<<i)))
                    binaryBits[i]++; //increasing the count of numbers in the given array for which the ith index bit is set.
            }
        }
        
        int singleNo = 0;
        
        for(int i=0;i<32;i++)
        {
            if(binaryBits[i]%3 != 0) //if for any position, the count of numbers in the given array for which the ith index bit is set, is a multiple of 3, that means this ith set bit is not set in the number that appears only once. If any ith index count is not divisible by 3, that means this ith set bit is included in the number that appears only once.
                singleNo = ((1 << i) | singleNo); //making the ith bit set in our final answer variable (which is at first initialized to 0)
        }
        
        return singleNo;
        
    }
};