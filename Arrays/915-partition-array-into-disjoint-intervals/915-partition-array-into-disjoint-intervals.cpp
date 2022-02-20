class Solution {
public:
//INTUITION: If at any index, the maximum element on the left is less that the minimum element on the right
    int partitionDisjoint(vector<int>& nums) {
        if(nums.size()==2)
            return 1;
        int n = nums.size();
        vector<int> leftMax(nums.size());
        leftMax[0] = nums[0];
        vector<int> rightMin(nums.size());
        rightMin[n-1] = nums[n-1];
        for(int i = 1; i<n; i++)
        {
            leftMax[i] = max(nums[i],leftMax[i-1]);
            rightMin[n-i-1] = min(nums[n-i-1],rightMin[n-i]);
        }
        for(int i = 0; i+1<nums.size(); i++)
            if(leftMax[i]<=rightMin[i+1])
                return i+1;
        return -1;
    }
};