class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int freq[2]{0};
        int start = 0, currSubstrMaxFreq = 0;
        int ans = 0,end = 0;
        for( end = 0; end<nums.size(); ++end)
        {
            ++freq[nums[end]];
            //if(!nums[end]) currSubstrMaxFreq = freq[0];
            int currSubstrLen = end-start+1;
            if(currSubstrLen - freq[1] > k) --freq[nums[start++]];
            //else if(freq[1]>freq[0]) ans = max(ans,freq[]);
        }
        return end-start;
    }
};