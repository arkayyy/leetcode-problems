class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto&a:arr) ++mp[a];
        vector<pair<int,int>> nums;
        for(auto&m: mp)
            nums.push_back({m.second,m.first});
        sort(nums.begin(),nums.end());
        int rem= 0;
        for(int i = 0; i<nums.size();++i)
        {
            if(nums[i].first>k) break;
            ++rem;
            k-=nums[i].first;
        }
        return nums.size()-rem;
    }
};