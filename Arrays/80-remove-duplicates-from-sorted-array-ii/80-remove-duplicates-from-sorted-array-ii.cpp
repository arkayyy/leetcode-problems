class Solution {
public:
    //ALGO: We use 2 pointers. We will use the 2nd pointer to check for equal elements, and if less than k equal consecutive elems are found, 
    //we put that value into the 1st pointer position and move both pointer forward. If more than k found, we don't move 1st pointer pointer forward,
    //we keep forwarding the 2nd pointer until repeating consecutive elements are found again.
    
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1;
        int k = 2;//max limit of consecutive elements
        int cnt = 1;
        while(j<nums.size())
        {
            if(nums[j]!=nums[j-1])
            {
                cnt = 1; //if consecutive elems found not equal, cnt back to 1 since, cnt counts the number of consecutive equal elements
                nums[i] = nums[j];
                i++, j++; //if not equal, we don't need to count consecutive equal elements 
            }
            else //if nums[j]==nums[j-1], i.e. equal elements found consecutively
            {
                if(cnt<k) //we will put jth element value at pointer i only if the current number of consecutive equal elements is less than k (limit of consecutive equal elements)
                {
                    nums[i] = nums[j];
                    i++; //the ith index stands back where the next new number will come up, after the next new number comes i is forwarded one step (continiuosly only upto k times)
                    cnt++;
                }
                j++; //if cnt>=k only j pointer goes on increasing, and next time will come into this block only when another consecutive equal elements are found...
            }
        }
        
        return i;
    }
};