class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorsum = nums[0];
        for(auto i=1;i<nums.size();i++)
            xorsum = xorsum ^ nums[i];
        return xorsum;
    }
};