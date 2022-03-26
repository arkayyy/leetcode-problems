class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        //INTUITION: Sliding window (WORKS ONLY FOR +VE NOS. in ARRAY)
        // int sum = nums[0];
        // int i = 0, j = 0;
        // int cnt = 0;
        // while(j<nums.size())
        // {
        //     if(sum==target)
        //     {
        //         ++cnt;
        //         sum = 0;
        //         ++j;
        //         i = j;
        //         if(j<nums.size())
        //             sum+=nums[j];
        //     }
        //     else if(sum>target)
        //     {
        //         if(i==j)
        //         {
        //             sum-=nums[i];
        //             i++,j++;
        //             if(j<nums.size())
        //                 sum+=nums[j];
        //         }
        //         else
        //         {
        //             sum-=nums[i];
        //             i++;
        //         }
        //     }
        //     else
        //     {
        //             ++j;
        //             if(j<nums.size())
        //                 sum+=nums[j];
        //     }
        // }
        
        //=============works for both +ve and -ve numbers in array==================//
        
        //INTUITION: Store the sum encountered at each index in a map and 
        //if we have two pointers, one at the end of previous subarray meeting the criteria, and one at the starting of a new subarray meeting the criteria
        //we can check if these two subarrays overlap
        
        
        unordered_map<int,int> mp;
        mp[0] = -1; //for handling the case if subarray with sum ==5 starts from the 0th index itself 
        int cnt = 0, sum = 0, right = -1, left = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            sum+=nums[i]; //recurring sum
            if(mp.count(sum-target))
            {
                left = mp[sum-target]; //starting point of current subarray with sum == target
                if(left>=right) //non-overlapping condition
                {
                    ++cnt;
                    right = i; //marking the ending of current subarray which has been counted
                }
            }
            mp[sum] = i; // marking each encountered sum's index
        }
        
        return cnt;
    }
};