class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
vector<int> ans;
        
        //if the array is 1,2,3,4,5. by putting a large number in between two smaller numbers, it can't be the average of those two ever. so we sort the array, add one small element from starting ,
        //and one big element from the ending of the array to the final answer sequence.
        sort(nums.begin(),nums.end());
        int lo = 0, hi = nums.size()-1;
        
        while(lo<hi)
        {
            ans.push_back(nums[lo]);
            ans.push_back(nums[hi]);
            
            lo++;
            hi--;
        }
        
        if(lo==hi) ans.push_back(nums[lo]);
        
        return ans;
    }
};