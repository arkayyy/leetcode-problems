class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> leftMax(n);
        vector<int> rightMin(nums.size());
        
        leftMax[0] = nums[0]; rightMin[n-1] = nums[n-1];
        
        for(int i = 1; i<nums.size(); i++)
        {
            leftMax[i] = max(nums[i], leftMax[i-1]);
            rightMin[n-i-1] = min(nums[n-i-1], rightMin[n-i]);
        }
        int ans = 0;
        
        for(int i = 1; i<n-1; i++)
        {
            if(nums[i]>leftMax[i-1] && nums[i]<rightMin[i+1])
                ans+=2;
            else if(nums[i]>nums[i-1] && nums[i]<nums[i+1])
                ans+=1;
        }
        
//         for(auto i: leftMax)
//             cout<<i<<" ";
//         cout<<endl;
//         for(auto i: rightMin)
//             cout<<i<<" ";
//         cout<<endl;
        
        
        return ans;
    }
};