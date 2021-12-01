class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        
        int minDiff = INT_MAX, minDiffSum;
        
        for(int i = 0;i<=nums.size()-3;i++)
        {
            int j = i+1;
            int k = nums.size()-1;


            while(j<k)
            {
                if(nums[j]+nums[k]+nums[i] == target) return target;
                
                if(abs(target-nums[i]-nums[j]-nums[k] )< minDiff){
                    minDiff = abs(target-nums[j]-nums[k]-nums[i]);
                    minDiffSum = nums[i]+nums[j]+nums[k];
                }
                
                else if(nums[j]+nums[k]+nums[i] > target) k--;
                
                else {
                  
                    j++;}
            }
        }

        
        return minDiffSum;
    }
};