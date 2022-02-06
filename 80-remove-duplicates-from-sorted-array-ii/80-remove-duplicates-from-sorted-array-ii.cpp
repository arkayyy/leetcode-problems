class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1;
        int k = 2; //limit
        int cnt = 1; //counting nums[0] initially
        while(j<nums.size())
        {
            if(nums[j]!=nums[j-1])
            {
                cnt = 1;
                nums[i] = nums[j];
                i++,j++;
            }
            else
            {
                if(cnt<k)
                {
                    nums[i] = nums[j];
                    cnt++;
                    i++;
                }
                j++;
            }
        }
        return i;
    }
};