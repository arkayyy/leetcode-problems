class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(auto t:tasks) ++mp[t];
        int ans = 0;
        for(auto m:mp) {
            if(m.second==1) return -1;
            ans+=m.second/3 + (m.second%3!=0 ? 1 : 0);
        }
        return ans;
    }
};