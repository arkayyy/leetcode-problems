class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxel = *max_element(nums.begin(),nums.end());
        int maxelIndex = max_element(nums.begin(),nums.end()) - nums.begin();
        
        for(int i=0; i<nums.size(); i++)
        {
            if(i!=maxelIndex)
            {
                if(nums[i]*2 > maxel)
                    return -1;
            }
        }
        
        return maxelIndex;
    }
};