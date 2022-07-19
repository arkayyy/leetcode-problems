class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0,maxi = INT_MIN;
        for(auto&n:nums)
        {
            sum+=n;
            maxi = max(maxi,sum);
            if(sum<0) sum = 0;
        }
        return maxi;
    }
};