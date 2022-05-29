class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = nums.size();
        for(int i = 0; i<nums.size(); ++i) xor1 ^= nums[i] ^i;
        return xor1;
    }
};