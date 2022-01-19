class Solution {
public:
    //INTUITION: If we employ merge sort here, we can do something similar to count inversions...
    
    //ALGO: In count inversions, we check if arr1[p1]>arr2[p2] then it's considered an inversion
    //Here we simply check if arr1[p1]>2*arr2[p2] and consider that as reverse pair..so all elements in arr1 appearing after p1 also form reverse pairs with p2th element of arr2..
    int merge(int i, int mid, int j, vector<int>&temp, vector<int>& arr)
    {
        int x = i;
        int y = mid+1;
        int z = i; //will be used for storing elems in temp array (in fully sorted fashion)
        int revc = 0;
        //counting reverse pairs
        for(int p = i;p<=mid;p++){
            while(y<=j && (long)arr[p]>2*(long)arr[y]) y++;
            revc+=y-(mid+1);
        }
       
        //sorting using original merge method -----
        x = i, y = mid+1, z = i;
        while(x<=mid && y<=j)
        {
            if(arr[x]>arr[y]) temp[z++] = arr[y++]; 
            else temp[z++] = arr[x++];
        }
        while(x<=mid) temp[z++] = arr[x++];
        while(y<=j) temp[z++] = arr[y++];
        
        for(int p = i; p<=j;p++) arr[p] = temp[p];
        //----merging ends
        return revc;
    }
    
    int mergeSort(int i, int j, vector<int>&temp, vector<int>& nums)
    {
        if(i>=j) return 0;
        int mid = i+((j-i)>>1);
        int revc = 0;
        revc+=mergeSort(i,mid,temp,nums);
        revc+=mergeSort(mid+1,j,temp,nums);
        revc+=merge(i,mid,j,temp,nums);
        return revc;
    }
    
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        return mergeSort(0,nums.size()-1,temp,nums);
    }
};