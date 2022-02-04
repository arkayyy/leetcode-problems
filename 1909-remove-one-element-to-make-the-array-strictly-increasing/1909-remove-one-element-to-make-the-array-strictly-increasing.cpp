class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int prev = nums[0];
        bool usedRemoval = false;
        for(int i = 1; i<nums.size(); i++)
        {
            if(nums[i]<=prev)
            {
                if(usedRemoval) return false; //if already used up but still a descending sequence is found
                usedRemoval = true;
                
                if(i==1 || nums[i]>nums[i-2]) prev = nums[i]; //if seq is something like ..100,21,101.., 21 removed from middle and prev shifted to 101
            }
            else
                prev = nums[i];
        }
        return true;
    }
};