class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        //INTUITION: Similar to 2 sum problem...
        
        //==========================APPROACH 1: Frequency map Time O(2N) Space O(N) =======================================//
        // unordered_map<int,int> freq;
        // for(auto n: nums) freq[n]++;
        // int ans = 0;
        // for(auto& m: freq)
        // {
        //     if(m.first==(k-m.first)) ans+=(m.second/=2);
        //     else{
        //         auto found = freq.find(k-m.first);
        //         if(found!=freq.end()) {
        //             int deduct = min(found->second,m.second);
        //             ans+=deduct;
        //             found->second-=deduct; m.second-=deduct;
        //         }
        //     }
        // }
        // return ans;
        
        //======================APPROACH 2: Sorting + 2Pointer TC: O(NlogN) SC:O(1) =========================================//
        sort(nums.begin(),nums.end());
        int ans = 0;
        int i = 0, j = nums.size()-1;
        while(i<j)
        {
            if(nums[i]+nums[j]>k) --j;
            else if(nums[i]+nums[j]<k) ++i;
            else ++i,--j,++ans;
        }
        return ans;
    }
};