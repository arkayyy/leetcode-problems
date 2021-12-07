class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int decr = 0, eq = 0;
        
        for(int i = 1; i<nums.size();i++)
        {
            if(nums[i]<nums[i-1]){
                if(decr) return false;
                decr++;
                if(i>1 && i<(nums.size()-1) && nums[i]<nums[i-2] && nums[i-1]>nums[i+1])
                    return false;
            }
        }
        
        return true;
    }
};