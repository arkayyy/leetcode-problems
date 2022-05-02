class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int evenIdx = 0, oddIdx = nums.size()-1;
        while(evenIdx<oddIdx)
        {
            if(!(nums[evenIdx]&1) && (nums[oddIdx]&1)) {++evenIdx,--oddIdx; continue;}
            else if((nums[evenIdx]&1)&& !(nums[oddIdx]&1)) swap(nums[oddIdx],nums[evenIdx]);
            else if((nums[evenIdx]&1)) --oddIdx;
            else if(!(nums[oddIdx]&1)) ++evenIdx;
        }
        return nums;
    }
};