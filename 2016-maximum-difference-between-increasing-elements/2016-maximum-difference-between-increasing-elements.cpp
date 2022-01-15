class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini = INT_MAX;
        int maxDiff = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i]<mini)
            {
                mini = nums[i];
            }
            else
            {
                maxDiff = max(maxDiff, nums[i] - mini);
            }
        }
        return (maxDiff==0 ? -1 : maxDiff);
    }
};