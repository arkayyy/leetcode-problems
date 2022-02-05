class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        
        vector<int> prefix(nums.size()+1,0);
        prefix[1] = nums[0];
        for(int i = 2; i<=nums.size(); i++)
            prefix[i] = prefix[i-1]+nums[i-1];
        
        int sum = 0;
        
        int ans = INT_MIN;
        
        for(int i = 0; i<nums.size(); i++)
            sum+=(i*nums[i]);
        //handling edge cases for no. of elems = 1,2 and 3
        if(nums.size()==1 || nums.size()==2 )
            return sum;
        ans = max(ans,sum);
        
        int size = nums.size()-1;
        
        int i = 0, j = i+size-1;
        
        int subtractor = (nums.size()-1)*nums[(j+1)%nums.size()];
        int adder = prefix[(j+1)%nums.size()] ;
            
        for(int k = 1; k<= nums.size()-1; k++)
        {
            sum-= subtractor;
            sum+=adder;
            ans = max(ans, sum);
            i = (j+1)%nums.size();
            j = (i+size-1)%nums.size();
            subtractor = (nums.size()-1)*nums[(j+1)%nums.size()];
            adder = prefix[(j+1)%nums.size()] + (prefix[nums.size()]-prefix[i]);
        }
        
        return ans;
        
    }
};