class Solution {
public:
    
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long> prefix(nums.size(),0); //can also be done in O(1) space, instead of takign a prefix sum array we can take one single sum variable
        //then we can keep including one element in left half and eliminate one element from right half, and calc the avg difference at every step
        for(int i = 0; i<nums.size(); i++)
            prefix[i] = (i>0?prefix[i-1]:0)+nums[i];
        int minDiff = INT_MAX;
        int ans = 0, res;
        for(int i = 0; i<nums.size()-1; i++)
        {
            res = abs((int)(prefix[i]/(i+1)) - (int)((prefix[nums.size()-1]-prefix[i])/(nums.size()-i-1)));
            if(res<minDiff)
            {minDiff = min(res,minDiff); ans = i;}
        }
        res = (int)(prefix[nums.size()-1]/(nums.size()));
        if(res<minDiff)
            ans = nums.size()-1;
        return ans;
        
    
    }
};