class Solution {
public:
    int findParent(vector<int>& ds, int i) {
  return ds[i] < 0 ? i : ds[i] = findParent(ds, ds[i]);
}
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> ds(s.size(), -1); //disjointed set
        vector<vector<int>> m(s.size());//map to map all associated indices of index
        for (auto& p : pairs) {
            auto i = findParent(ds, p[0]), j = findParent(ds, p[1]);
            if (i != j) //if both don't have same parent
                ds[j] = i;
        }
        for (auto i = 0; i < s.size(); ++i) 
            m[findParent(ds, i)].push_back(i); 
        for (auto &ids : m) {
            string res = "";
            for (auto id : ids) 
                res += s[id]; 
            sort(begin(res), end(res)); //sorting at every step to obtain the lexicographically smallest string
            for (auto i = 0; i < ids.size(); ++i) 
                s[ids[i]] = res[i]; //replacing all indexes with their smallest associated characters that can be swapped with
        }
        
        return s;
    }
};