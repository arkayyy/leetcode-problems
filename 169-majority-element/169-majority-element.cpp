class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Moore's voting algorithm:-
        
        //INTUITION: since the major element is present more than half length of array, its net count will always be more than all the other elements count combined...
        
        //AALGO: We start with the first element and count as 1, as soon as a dissimilar element is found we decrease the count...
        //...as our count reaches 0, we reset the count to 1 and set the new element as candidate
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