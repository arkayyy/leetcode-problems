class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorsum = nums[0];
        for(auto i=1;i<nums.size();i++)
            xorsum = xorsum ^ nums[i]; //taking xor of all numbers, the nos. appearing twice will get cancelled,except the one that appears only once
        return xorsum;
    }
};