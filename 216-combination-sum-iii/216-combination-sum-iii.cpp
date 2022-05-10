class Solution {
public:
    void util(int i, int k, int n, vector<int>& res, vector<vector<int>>& ans)
    {
        if(n==0 && k==0)
        {ans.push_back(res); return;}
        
        if(n==0 || k==0) return;
        
        for(int t = i; t<=9;t++)
        {
            res.push_back(t);
            util(t+1, k-1, n-t,res,ans);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> res;
        util(1,k,n,res,ans);
        return ans;
    }
};