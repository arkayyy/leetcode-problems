class Solution {
public:

    //==================APPROACH 1 - BRUTE FORCE O(N^2) - Generating all substrings========================//
    int countDistinct(vector<int>& nums, int k, int p) {

        int n=nums.size();
        unordered_set<string>s;

        for(int i=0;i<n;i++)
        {
            string res = "";
            int cnt=0;
            for(int j=i;j<n;j++)
            {
                res += ((to_string(nums[j])+"-")); //adding "-" to handle the edge case of: 1,12 OR 11,2 in substring that would concatenate to the same string otherwise
                if(nums[j]%p==0)
                    ++cnt;
                if(cnt>k)
                    break;
                s.insert(res);
                    
            }
        }
        return s.size();
        
        
    }
};