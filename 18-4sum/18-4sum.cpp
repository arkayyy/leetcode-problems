class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<nums.size(); i++)
        {
            for(int j = i+1; j<nums.size(); j++)
            {
                int k = j+1, l = nums.size()-1;
                while(k<l)
                {
                    if((long long)nums[i]+nums[j]+nums[k]+nums[l] == (long long)target) 
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while(k<l && nums[k]==ans.back()[2]) ++k;
                        //while(l<l && nums[l]==ans.back()[3]) --l;
                    }
                    else if((long long)nums[i]+nums[j]+nums[k]+nums[l] < (long long)target)
                        k++;
                    else l--;
                }
                while(j+1<nums.size() && nums[j+1]==nums[j]) ++j;
            }
            while(i+1<nums.size() && nums[i+1]==nums[i]) ++i;
        }
        
        return ans;
    }
};