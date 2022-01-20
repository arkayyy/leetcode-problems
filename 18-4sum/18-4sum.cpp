class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        //using 4-pointer technique...an extension to the 3-sum problem
        //The extension is that here we also handle all duplicate quadruplets that we might get
        for(int i = 0; i<nums.size(); i++)
        {
            for(int j = i+1; j<nums.size(); j++)
            {
                int k = j+1, l = nums.size()-1;
                while(k<l)
                {
                    if((long long)nums[i]+nums[j]+nums[k]+nums[l]==(long long)target) 
                    {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        // IMP: Processing the duplicates of number 3 (since array is sorted all duplicates will be adjacent to each other consecutively)
                        while (k < l && nums[k] == ans.back()[2]) ++k;
                        // IMP: Processing the duplicates of number 4 (since array is sorted all duplicates will be adjacent to each other consecutively)
                        while (k < l && nums[l] == ans.back()[3]) --l;
                    }
                    else if((long long)nums[i]+nums[j]+nums[k]+nums[l]>(long long)target) l--;
                    else k++;
                }
                // IMP: Processing the duplicates of number 2 (since array is sorted all duplicates will be adjacent to each other consecutively)
                while(j + 1 < nums.size() && nums[j + 1] == nums[j]) ++j;
            }
            // IMP: Processing the duplicates of number 1 (since array is sorted all duplicates will be adjacent to each other consecutively)
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) ++i;
        }
        return ans;
    }
};