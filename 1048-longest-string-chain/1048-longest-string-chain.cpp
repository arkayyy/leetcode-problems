class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[&](const string&a, const string&b) {return a.size()<b.size();});
        unordered_map<string,int> mp;
        int maxi = 0;
        for(auto& w: words)
            for(int i = 0; i<w.size(); ++i)
                maxi = max(maxi, mp[w] = max(mp[w],1+mp[w.substr(0,i)+w.substr(i+1)]));
        return maxi;
    }
};