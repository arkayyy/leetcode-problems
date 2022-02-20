class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        for(auto n:nums)
            mp[n]++;
        
        int cnt = 0;
        for(auto n: mp)
        {
            if(k==0)
            {
                if(n.second>1)
                    cnt++;
            }
            else
            {
                if(mp.find(n.first+k)!=mp.end())
                    cnt++;
            }
        }
        
        return cnt;
    }
};