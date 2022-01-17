class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> mp;
        
        for(auto n: nums1) 
            mp[n]++;
        
        for(auto n:nums2) 
            if(mp[n]>0)
                {mp[n]--; ans.push_back(n);}
        return ans;
    }
};