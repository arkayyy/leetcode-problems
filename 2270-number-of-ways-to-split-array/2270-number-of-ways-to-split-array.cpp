class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sumr = 0;
        for(auto n: nums) sumr+=n;
        long long suml = 0;
        int ans = 0;
        for(int i = 0; i<nums.size()-1; i++)
        {
            suml+=nums[i];
            sumr -= nums[i];
            if(suml>=sumr) ++ans;
        }
        return ans;
    }
};