class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long prevIdxOddSum = 0, prevIdxEvenSum = 0;
        for(long long i = 0; i<nums.size(); ++i)
        {
            long long currIdxOddSum = 0, currIdxEvenSum = 0;
            currIdxOddSum = max(prevIdxOddSum,prevIdxEvenSum + nums[i]); //max b/w: (i) we don't consider current element so we continue with the sum till now with prev idx as odd and (ii) we consider curr element as odd index
            currIdxEvenSum = max(prevIdxEvenSum,prevIdxOddSum - nums[i]);//max b/w: (i) we don't consider current element so we continue with the sum till now with prev idx as even and (ii) we consider curr element as even index
            prevIdxOddSum = currIdxOddSum, prevIdxEvenSum = currIdxEvenSum;
        }
        return max(prevIdxOddSum,prevIdxEvenSum);
    }
};