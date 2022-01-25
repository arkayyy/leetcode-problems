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
        
        int i = idx;
        // while(i<nums.size())
        // {
            curr.push_back(nums[i]);
            util(i+1,curr,nums,ans);

            curr.pop_back();
            while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
            util(i+1,curr,nums,ans);
        //     i++;
        // }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans({{}});
        sort(nums.begin(),nums.end());
        util(0,curr,nums,ans);
        return ans;
    }
};