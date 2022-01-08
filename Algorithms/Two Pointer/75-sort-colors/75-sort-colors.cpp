class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        //ALGO: applying a 3 pointer approach here wherein we mainly traverse with the mid pointer, swap the mid element with lo if it is 0, or with hi if it is 2.
        int lo = 0, mid = 0, hi = nums.size()-1;
        
        while(mid<=hi)
        {
            if(nums[mid]==0)
            {
                swap(nums[lo],nums[mid]); //swapping mid element with lo, if mid element is 0, and forwarding both mid and lo
                lo++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++; //continuing if nums[mid]==1
                continue;
            }
            else if(nums[mid]==2)
            {
               swap(nums[mid],nums[hi]); //swapping mid element with hi, if mid element is 2, and forwarding ONLYY hi backwards
               hi--;
            }
        }
        
        //HURRAH...!!!
        
        
    }
};