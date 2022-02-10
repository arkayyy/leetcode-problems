class Solution {
public:
    
    
    string customSortString(string order, string s) {
        unordered_map<char,int> idx;
        for(int i = 0; i<order.size(); i++)
        {
            idx[order[i]] = i+1;
        }
    
        sort(s.begin(),s.end(),[&](char a, char b){return idx[a]<idx[b];});
        return s;
    }
};