class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = INT_MIN;
        int maxIndex = -1;
        int max2 = INT_MIN;
        for(int i = 0; i<nums.size(); i++)
            if(nums[i]>max1)
            {max1=nums[i]; maxIndex = i;}
        for(int i = 0; i<nums.size(); i++)
            if(nums[i]>max2 && nums[i]<=max1 && i!=maxIndex)
                max2 = nums[i];
        return (max2-1)*(max1-1);
    }
};