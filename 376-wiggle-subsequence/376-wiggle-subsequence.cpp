class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int firstElementPeak = 1, firstElementValley = 1;
        for(int i = 1; i<nums.size(); ++i)
            if(nums[i]>nums[i-1]) firstElementPeak =  firstElementValley+1;
            else if(nums[i]<nums[i-1]) firstElementValley = firstElementPeak +1;
        return max(firstElementPeak ,firstElementValley);
    }
};