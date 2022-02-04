class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        unordered_map<int,int> mp;
        
        int ans = 0;
        mp[0] = 0;
        for(int i = 1; i<=nums.size(); i++)
        {
            sum+=(nums[i-1]==1)?1:-1;
            if(mp.find(sum)!=mp.end())
            {
                ans = max(ans, i-mp[sum]);
            }
            else
            mp[sum] = i;
        }          
        return ans;
    }
};