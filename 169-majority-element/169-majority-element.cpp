class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int cand = nums[0], cnt = 1;
        for(int i = 1; i<nums.size(); i++)
        {
            if(cnt)
            {
                if(cand==nums[i]) cnt++;
                else cnt--;
            }
            else if(cnt==0)
                {cand = nums[i]; cnt =1;}
        }
        return cand;
    }
};