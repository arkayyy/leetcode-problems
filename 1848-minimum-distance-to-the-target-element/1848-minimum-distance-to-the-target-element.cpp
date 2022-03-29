class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        if(nums[start]==target) return 0;
        int i = start-1, j = start+1;
        
        while(i>=0 && j<nums.size())
        {
            if(nums[i]==target)
                return abs(start-i);
            if(nums[j]==target)
                return abs(start-j);
            
            i--,j++;
        }
        
        while(i>=0)
        {
            if(nums[i]==target)
                return abs(start-i);
            i--;
        }
        
        while(j<nums.size())
        {
            if(nums[j]==target)
                return abs(start-j);
            j++;
        }
        
        return -1;
    }
};