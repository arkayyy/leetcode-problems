class Solution {
public:
//     int maxProduct(vector<int>& nums) {
//         int mini = nums[0], maxi = nums[0];
//         int ans = maxi;
        
//         for(auto i=1;i<nums.size();i++)
//         {
//             //there can be only 3 conditions, if nums[i] = 0, negative, or positive. If nums[i] = -ve, our aim will be to set maxi as mini*nums[i], because -ve and -ve product might bring the biggest number. mini should be set to nums[i]*maxi, since negative*positive will bring the least number
//             //next if nums[i] = +ve, our aim to store maxi as maxi*nums[i], and mini as mini*nums[i].
//             //if nums[i] = 0, our aim is to reset both mini and maxi to 0;
//             int currMax = max({nums[i], mini*nums[i], maxi*nums[i]});
//             mini = min({nums[i],nums[i]*mini, nums[i]*maxi});
//             maxi = currMax;
//             ans = max(ans,maxi);
//         }
        
//         return ans;
//     }
    
    int maxProduct(vector<int>&nums){
        if(nums.size()==1) return nums[0];
        
        int maxi = nums[0], mini = nums[0];
        int ans = maxi;
        
        for(int i = 1; i<nums.size();i++)
        {
            
            int tmaxi = max(nums[i], max(maxi*nums[i], mini*nums[i]));
            mini = min(nums[i], min(mini*nums[i],maxi*nums[i]));
            maxi = tmaxi;
            ans = max(ans,maxi);
        }
        
        return ans;
    }
};