class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int evenIdx = 0, oddIdx = nums.size()-1;
        while(evenIdx<oddIdx)
        {
            if(!(nums[evenIdx]&1) && (nums[oddIdx]&1)) {++evenIdx,--oddIdx; continue;} //NO VIOLATION
            else if((nums[evenIdx]&1)&& !(nums[oddIdx]&1)) swap(nums[oddIdx],nums[evenIdx]); //will swap only in case of violation( odd number at evenIdx position and even number at oddIdx position)
            else if((nums[evenIdx]&1)) --oddIdx; //In case of only one violation, we shift only the other pointer which doesn't have violating element
            else if(!(nums[oddIdx]&1)) ++evenIdx;
        }
        return nums;
    }
};