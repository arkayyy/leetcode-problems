class Solution {
public:
    
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sumEven = 0;
        vector<bool> odd(nums.size(),false);
        
        for(int i= 0; i<nums.size(); i++)
        {
            if((nums[i]&1)==1)
            {
                odd[i] = true;
            }
            else
                sumEven += nums[i];
        }
            
        for(auto q: queries)
        {
            int adder = q[0];
            int idx = q[1];
            
            int res = nums[idx]+adder;
            
            if((res&1)==1)
            {
                if(!odd[idx])
                {
                   sumEven -= nums[idx];
                }
                odd[idx] = true; 
            }
            else
            {
                if(odd[idx])
                {
                    sumEven+=res;
                }
                else
                {
                    sumEven+=adder;
                }
                odd[idx] = false;
            }
            
            nums[idx] = res;
            
            ans.push_back(sumEven);
        }
        
        return ans;
    }
};