class Solution {
public:
    void util(int idx, vector<int> & curr,vector<int>&nums, vector<vector<int>> &ans)
    {
        if(idx>=nums.size()) 
        {
            if(curr.size()>0)
                ans.push_back(curr);
            return;
        }

        //including the current index element
        curr.push_back(nums[idx]);
        util(idx+1,curr,nums,ans);
        //not including the current index element or any of its repetitions occuring after it
        curr.pop_back(); //imp: backtracking step
        while(idx+1<nums.size() && nums[idx]==nums[idx+1]) idx++;
        util(idx+1,curr,nums,ans);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans({{}});
        sort(nums.begin(),nums.end());
        util(0,curr,nums,ans);
        return ans;
    }
};