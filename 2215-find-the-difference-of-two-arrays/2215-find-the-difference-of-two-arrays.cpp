class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());
        vector<int> t1;
        vector<int> t2;
        for(auto n: s1) if(s2.find(n)==s2.end()) t1.push_back(n);
        for(auto n: s2) if(s1.find(n)==s1.end()) t2.push_back(n);
        return {t1,t2};
    }
};