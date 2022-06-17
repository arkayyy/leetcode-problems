class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0], mini = nums[0];
        int ans = maxi;
        for(int i = 1; i<nums.size(); ++i)
        {
            int t = maxi;
            maxi = max({nums[i],mini*nums[i],maxi*nums[i]});
            mini = min({nums[i],mini*nums[i],t*nums[i]});
            ans = max(ans,maxi);
        }
        return ans;
    }
};