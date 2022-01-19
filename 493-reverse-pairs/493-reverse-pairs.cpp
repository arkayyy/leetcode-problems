class Solution {
public:
    int merge(int i, int mid, int j, vector<int>& temp, vector<int>& nums)
    {
        int p1 = i, p2 = mid+1;
        int p3 = i; 
        int revc = 0;
        //counting reverse pairs:-
        while(p1<=mid && p2<=j)
        {
            if((long)nums[p1]>(long)2*nums[p2]) {revc+=(mid+1-p1); p2++;}
            else p1++;
        }
        
        //merging the array
        p1 = i, p2 = mid+1;
        while(p1<=mid && p2<=j)
        {
            if(nums[p1]>nums[p2]) temp[p3++] = nums[p2++];
            else temp[p3++] = nums[p1++];
        }
        while(p1<=mid)
            temp[p3++] = nums[p1++];
        while(p2<=j) 
            temp[p3++] = nums[p2++];
        
        for(int x = i; x<=j; x++) nums[x] = temp[x];
        
        return revc;
    }
    int mergeSort(int i, int j, vector<int>& temp, vector<int>& nums)
    {
        if(i>=j) return 0;
        int revc = 0;
        int mid = i+((j-i)>>1);
        revc+=mergeSort(i,mid,temp, nums);
        revc+=mergeSort(mid+1,j, temp,nums);
        revc+=merge(i,mid,j,temp,nums);
        return revc;
    }
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        return mergeSort(0,nums.size()-1,temp,nums);
    }
};