class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>> ans;
        string prefix = "";
        for(auto& c: searchWord)
        {
            prefix +=c;
            int idx = lower_bound(products.begin(),products.end(),prefix) - products.begin();
            ans.push_back({});
            for(int t = idx, i = 0;i<3 && t<min((int)products.size(),idx+3) && products[t].find(prefix)!=-1;++i,++t)
                    ans.back().emplace_back(products[t]);
        }
        return ans;
    }
};