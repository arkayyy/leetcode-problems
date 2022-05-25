class Solution {
public:
    void util(int i, int target, vector<int>& curr, vector<int>&candidates, vector<vector<int>>& ans)
    {
        if(!target) {ans.push_back(curr); return;}
        if(i==candidates.size()) { if(!target) {ans.push_back(curr);}  return;}
        
        for(int t = i; t<candidates.size();++t)
        {
            if(t != i && candidates[t]==candidates[t-1])               //to avoid picking up the same combnation
                continue;
            if(candidates[t]<=target)
            {
                
                curr.emplace_back(candidates[t]);
                util(t+1,target-candidates[t],curr,candidates,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        util(0,target,curr,candidates,ans);
        return ans;
    }
};