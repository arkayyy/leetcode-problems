class Solution {
public:
    void util(int idx, vector<int>&candidates, int sum, vector<int>& curr, int target, vector<vector<int>>& ans)
    {
        if( sum>target) return;
        if(sum==target){ans.push_back(curr); return;}
        
        for(int i =idx; i<candidates.size();i++)
        {
            curr.push_back(candidates[i]);
            util(i,candidates,sum+candidates[i],curr,target, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        util(0,candidates,0,curr,target, ans );
        return ans;
    }
};