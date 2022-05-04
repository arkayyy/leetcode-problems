class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto n: nums) freq[n]++;
        int ans = 0;
        for(auto& m: freq)
        {
            if(m.first==(k-m.first)) ans+=(m.second/=2);
            else{
                auto found = freq.find(k-m.first);
                if(found!=freq.end()) {
                    int deduct = min(found->second,m.second);
                    ans+=deduct;
                    found->second-=deduct; m.second-=deduct;
                }
            }
        }
        return ans;
    }
};