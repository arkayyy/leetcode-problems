class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        
        int ans = nums[0]+nums[1]+nums[2]; //taking first 3 numbers in the triplet just to initialize (it can be any 3 numbers in the array)
        
        for(int i = 0;i<=nums.size()-3;i++)
        {
            int j = i+1;
            int k = nums.size()-1;


            while(j<k) //2 pointer method
            {   int sum = nums[i]+nums[j]+nums[k];
                if(sum == target) return target;
                
                if(abs(sum-target )< abs(ans-target)){ //main step...if the diff between current sum and the target is less than the difference between the already stored ans and target, then update ans as the current sum.
                    ans = sum;
                }
                
                else if(sum > target) k--;
                
                else {//if sum<target
                    j++;}
            }
        }

        
        return ans;
    }
};