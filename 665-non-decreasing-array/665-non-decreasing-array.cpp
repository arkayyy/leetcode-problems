class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool decreasing = false;
        for(int i = 1; i<nums.size(); ++i)
        {
            if(nums[i]>=nums[i-1]) continue;
            if(decreasing) return false;
            decreasing = true;
            if(i>=2 && i<nums.size()-1 &&  (nums[i-2]>nums[i] && nums[i-1]>nums[i+1]))
                return false;
        }
        return true;
    }
};