class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        unordered_map<int,vector<int>> richerAdj;
        for(auto &r: richer)
            richerAdj[r[1]].emplace_back(r[0]);
        vector<int> res(quiet.size(),-1);
        for(int i = 0;i<quiet.size(); ++i)
            dfs(i,quiet,res,richerAdj);
        return res;
    }
    
     int dfs(int i, vector<int>& quiet, vector<int>& res, unordered_map<int,vector<int>>&richerAdj) {
        if (res[i] >= 0) return res[i];
        res[i] = i;
        for (int j : richerAdj[i]) if (quiet[res[i]] > quiet[dfs(j, quiet,res,richerAdj)]) res[i] = res[j];
        return res[i];
    }
};