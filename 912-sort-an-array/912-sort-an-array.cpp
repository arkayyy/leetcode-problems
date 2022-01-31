class Solution {
public:
    void merge(int i,int mid, int j, vector<int>& temp, vector<int>& nums)
    {
        int p1 = i, p2 = mid+1, p3 = i;
        while(p1<=mid && p2<=j)
        {
            if(nums[p1]<=nums[p2]) temp[p3++] = nums[p1++];
            else temp[p3++] = nums[p2++];
        }
        
        while(p1<=mid) temp[p3++] = nums[p1++];
        while(p2<=j) temp[p3++] = nums[p2++];
        
        for(int x = i; x<=j; x++) nums[x] = temp[x];
    }
    void mergeSort(int i, int j, vector<int>& temp, vector<int>& nums)
    {
        if(i>=j)
            return;
        int mid = i+((j-i)>>1);
        mergeSort(i,mid,temp,nums);
        mergeSort(mid+1,j,temp,nums);
        merge(i,mid,j,temp,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        // for(int i = 1; i<nums.size(); i++)
        // {
        //     int temp = nums[i];
        //     int j = i-1;
        //     while(j>=0 && nums[j]>temp)
        //     {
        //         nums[j+1] = nums[j];   
        //         j--;
        //     }
        //     nums[j+1] = temp;
        // }
        // return nums;
        vector<int> temp(nums.size(),0);
        mergeSort(0,nums.size()-1,temp,nums);
        return nums;
    }
};