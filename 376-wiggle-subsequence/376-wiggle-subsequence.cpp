class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
    //purpose of total1 and total2 both are to store the total number of peaks and valleys
        int total1 = 1, total2 = 1; //total1->updated only when a new peak is found; total2-> updated whenever a new valley found
        for(int i = 1; i<nums.size(); ++i)
        {
            if(nums[i]>nums[i-1]) total1 = total2+1;
            else if(nums[i]<nums[i-1]) total2 = total1+1;
        }
        //total1 and total2(or vice versa) will always have a difference of 1
        return max(total1,total2);
    }
};