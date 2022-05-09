class Solution {
public:
    //ALGO: Modified merge sort
    int merge(int i, int mid, int j, vector<int>& temp, vector<int>& nums)
    {
        int p1 = i, p2 = mid+1;
        int p3 = i; 
        int revc = 0;
        //counting reverse pairs:-
        while(p1<=mid && p2<=j)
        {
            if((long)nums[p1]>(long)2*nums[p2]) {revc+=(mid+1-p1); p2++;} //IMP..since both halves are sorted, if thye element on ith index makes a reverse pair with jth index element
            //that means that every element greater than ith element will also make the same reverse pair with jth element...!!!
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
        int mid = i+((j-i)>>1);
        return mergeSort(i,mid,temp, nums)+mergeSort(mid+1,j, temp,nums)+merge(i,mid,j,temp,nums);
    }
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        return mergeSort(0,nums.size()-1,temp,nums);
    }
};