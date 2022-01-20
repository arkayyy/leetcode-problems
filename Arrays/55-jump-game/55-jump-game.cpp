class Solution {
public:
  
    bool canJump(vector<int>& nums) {
        int steps = nums[0];
    
        for(int i = 1; i<nums.size(); i++)
        {
            steps--;
            if(steps<0) return false; //all steps have depleted so can't move ahead.
            steps = max(steps,nums[i]); // updating max step size from current index i
        }
        return true;
        
    }
};