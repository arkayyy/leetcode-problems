class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for(auto n: nums) temp.push_back(to_string(n));
        sort(temp.begin(), temp.end(), [](const string &s1, const string &s2){return s1+s2>s2+s1;});
        string ans = "";
        for(auto t: temp) ans+=t;
        return ans[0]=='0'?"0":ans;
    }
};