class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        
        int n = nums.size();
        
        vector<int>ans;
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        
        //The IDEA is:
        //if the array is 1,2,3,4,5.
        //the product of the whole array without 3 will be equal to product of all numbers before 3 with the product of all numbers after 3 in the array.
        //the before and after elements product results are stored in prefix and suffix array respetively.
        
        for(int i = 0;i<n;i++)
        {
            prefix[i] = ((i-1>=0)?prefix[i-1]:1)*nums[i];
            suffix[n-1-i] = ((i==0)?1:suffix[n-i])*nums[n-1-i];
        }
        
        ans.push_back(suffix[1]);
        
        for(int i = 1 ; i<n-1 ; i++)
        {
            ans.push_back(prefix[i-1]*suffix[i+1]);
        }
        
        ans.push_back(prefix[n-2]);
        
        return ans;
        
        
    }
};