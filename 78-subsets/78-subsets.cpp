class Solution {
public:
    //Using the concept of power sets in bit manipulaton.
    vector<vector<int>> subsets(vector<int>& nums) {
        int ss = nums.size();
        int css = pow(2,ss);
        vector<vector<int>> ans;
        for(int i=0;i<css;i++)
        {vector<int>t;
            for(int j=0;j<ss;j++)
            {
               if(i & (1<<j))
                   t.emplace_back(nums[j]);
            }
         ans.push_back(t);
        }
        return ans;
    }
};