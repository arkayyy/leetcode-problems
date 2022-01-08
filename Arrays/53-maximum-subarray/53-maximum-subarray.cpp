class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_ending_here = 0, max_so_far = INT_MIN;
        for(auto num: nums)
        {
            max_ending_here = max( num , num + max_ending_here );
            max_so_far = max(max_ending_here, max_so_far);
        }
        return  max_so_far;
    }
};