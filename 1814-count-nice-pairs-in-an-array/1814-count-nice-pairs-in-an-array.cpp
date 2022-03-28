class Solution {
public:
    //INTUITION: Think of the condition given as a mathematical equation and try to rearrange it
    
    // nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
    //also denotes: nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
    
    //So the crux is that we have to count all repeating occurences of (nums[i]-rev(nums[i]) ) for all the indexes i in nums
    
    //ALGO: Use a map to store the frequency of nums[i]-rev(nums[i]) for all indexes in nums
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> cnt;
        int ans = 0;
        for(int n: nums)
        {
            int res = n - rev(n);
            ans=(ans+cnt[res])%(int)(1e9+7); //if nums[i]-rev(nums[i]) has occured earlier for multiple values of i in the past
            //...this current value will make a nice pair will all such indexes occured in the past 
            cnt[res]++; //counting for the current index
        }
        return ans;
    }
    int rev(int num)
    {
        int res = 0;
        while(num)
        {
            res = res*10 + (num%10);
            num/=10;
        }
        return res;
    }
};