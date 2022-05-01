class Solution {
public:
    
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long> prefix(nums.size(),0); //can also be done in O(1) space, instead of takign a prefix sum array we can take one single sum variable
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
        
        //Space optimised:-
        // long long leftCnt = 0, sumLeft = 0;
        // long long rightCnt = nums.size(), sumRight = accumulate(nums.begin(), nums.end(),0);
        // long long minDiff = LLONG_MAX, idx = 0;
        // for(int i = 0; i<nums.size(); i++)
        // {
        //     sumLeft += nums[i]; ++leftCnt;
        //     sumRight -= nums[i]; --rightCnt;
        //     if(abs((sumLeft/leftCnt) - (sumRight/max(rightCnt,(long long)1))) < minDiff)
        //     {
        //         minDiff = abs((sumLeft/leftCnt) - (sumRight/max(rightCnt,(long long)1)));
        //         idx = i;
        //     }   
        // }
        // return (int)idx;
    }
};