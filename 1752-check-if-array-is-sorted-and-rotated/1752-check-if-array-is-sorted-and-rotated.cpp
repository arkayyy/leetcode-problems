class Solution {
public:
    bool check(vector<int>& nums) {
        int decr = 0;
        for(int i = 0; i<nums.size()-1; ++i) if(nums[i+1]<nums[i]) {if(decr>0) return false; 
                                                                    ++decr;}
        if(decr==0) return true;
        return nums[0]>=nums[nums.size()-1];
    }
};