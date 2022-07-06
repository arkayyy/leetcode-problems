class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int freq[2]{0};
        int start = 0;
        int ans = 0,end = 0;
        for( end = 0; end<nums.size(); ++end)
        {
            ++freq[nums[end]];
            int currSubstrLen = end-start+1;
            if(currSubstrLen - freq[1] > k) --freq[nums[start++]];
            else ans = max(ans,currSubstrLen);
        }
        return ans;
    }
};