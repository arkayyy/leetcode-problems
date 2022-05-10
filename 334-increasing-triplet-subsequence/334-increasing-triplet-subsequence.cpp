class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)return false;
        vector<int> maxRight(nums.size());
        vector<int> minLeft(nums.size());
        minLeft[0] = nums[0]; maxRight[nums.size()-1] = nums.back();
        for(int i = 1; i<nums.size();i++) {minLeft[i] = min(nums[i], minLeft[i-1]); maxRight[nums.size()-1-i] = max(nums[nums.size()-i-1],maxRight[nums.size()-i]); }
        
        for(int i = 1; i<nums.size()-1; i++)
        {
            if(minLeft[i-1]<nums[i] && nums[i]<maxRight[i+1])
                return true;
        }
        return false;
    }
};