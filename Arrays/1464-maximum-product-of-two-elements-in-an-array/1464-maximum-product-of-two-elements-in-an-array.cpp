class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        for(int i = 0; i<nums.size(); i++)
            if(nums[i]>=max1) //found a number greater than both max1 and max2,so updating both
            {
                max2 = max1;
                max1=nums[i]; 
            }
            else if(nums[i]>max2) //found a number just greater than max2 so updating only that
            {
                max2 = nums[i];
            }
        
        return (max2-1)*(max1-1);
    }
};