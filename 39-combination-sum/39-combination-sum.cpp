class Solution {
public:
    
    //INTUITION: simple backtracking, once select an element and once don't 
    void util(int idx, vector<int>&candidates, int sum, vector<int>& curr, int target, vector<vector<int>>& ans)
    {
        if( sum>target) return;
        if(sum==target){ans.push_back(curr); return;}
        
        for(int i =idx; i<candidates.size();i++)//note: we are starting to select elements only from idx, i.e.the element that had been just previosuly selected, and not from any element selected earlier than that.
            //e.g. if we selected 2,2,3 before..now we can select elements only 3 and after 3 in our combination, we can't select 2 anymore
        {
            curr.push_back(candidates[i]);
            util(i,candidates,sum+candidates[i],curr,target, ans);
            curr.pop_back(); //for backtracking
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        util(0,candidates,0,curr,target, ans );
        return ans;
    }
};