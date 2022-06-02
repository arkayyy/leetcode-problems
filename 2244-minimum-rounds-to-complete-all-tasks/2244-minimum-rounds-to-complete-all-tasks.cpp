class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(auto t:tasks) ++mp[t];
        int ans = 0;
        for(auto m:mp) {
            if(m.second==1) return -1;
            else if(m.second%3==0) ans += m.second/3;
            else ans+=m.second/3 + 1;
        }
        return ans;
    }
};