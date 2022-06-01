class Solution {
public:
    //INTUITION: Sum of distant elements would always be less than sum of nearby elements. e.g. sum of 1 and 4 is lesser than sum of 3 and 4. 
    //So our target will be to consider sums of as distant elements as possible.
    
    //ALGO: We sort the array in ascending order and keep taking one element from start and one from end, and do their sum, so that most distant elements sum are considered.
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i = 0; i<nums.size()/2; ++i)
            ans = max(ans, nums[i]+nums[nums.size()-1-i]);
        return ans;
    }
};