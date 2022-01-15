class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return {};
        if(nums.size()==1) return {to_string(nums[0])};
        
        int start=nums[0];
        vector<string> ans;
        int i = 0;
        while(i<nums.size())
        {
            while(i<nums.size()-1 && nums[i]+1==nums[i+1])
                i++;
            if(start==nums[i]) 
                ans.push_back(to_string(start));
            else 
                ans.push_back(to_string(start)+"->"+to_string(nums[i]));
            i++;
            if(i<nums.size())
                start = nums[i];
        }
        return ans;
    }
};