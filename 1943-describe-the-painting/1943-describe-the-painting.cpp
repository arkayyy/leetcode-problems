class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int,long long> mp;
        for(auto& s: segments)
            mp[s[0]]+=s[2], mp[s[1]]-=s[2];
        
        int prevEnd = 0;
        vector<vector<long long>> ans;
        for(auto& m: mp)
        {
            if(mp[prevEnd]>0) ans.push_back({prevEnd,m.first,mp[prevEnd]});
            mp[m.first]+=mp[prevEnd];
            prevEnd = m.first;
        }
        
        return ans;
    }
};