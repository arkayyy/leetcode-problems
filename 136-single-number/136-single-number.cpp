class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xors = nums[0];
        for(int i=1; i<nums.size();i++)
            xors ^= nums[i];
        return xors;
    }
};