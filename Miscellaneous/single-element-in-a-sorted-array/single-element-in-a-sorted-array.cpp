class Solution {
public:
    bool isValid(vector<int>&nums, int start, int end)
    {
        if(end>=start)
            false;
        if(end-start==1)
            return nums[start]==nums[end];
            
        int i = 0;
        for(i = start; i<=end-1 ;i+=2)
        {
            if(nums[i]!=nums[i+1])
                return false;
        }
      
        return true;
       
    }
    int singleNonDuplicate(vector<int>& nums) {
        
        if(nums.size()==1)  //if there's only one element, that's the non repeating one
            return nums[0];
        
        if(nums[0]!=nums[1])//if the first element is the desired element
            return nums[0];
        if(nums[nums.size()-2]!=nums[nums.size()-1]) //if the last element is the desired element
            return nums[nums.size()-1];
        
        int lo = 0, hi = nums.size()-1;
        
        while(lo<=hi)
        {
            //cout<<lo<<"-"<<hi<<endl;
            int mid = lo+((hi-lo)>>1);
            
            if(nums[mid]!=nums[mid-1] && nums[mid+1]!=nums[mid]) //checking if the desired element lies at mid itself
            {
                lo = mid;
                break;
            }
            
            if(isValid(nums,lo,mid)) //checking to shift into the right range if left part is totally valid(repeating)
                { if(nums[mid]==nums[mid+1]) 
                    lo=mid+2;  //if the number at mid is repeating we need to skip that in order to give valid results ,e.g. in the case of [7,7,10,11,11,12,12], the middle element 11 should go in either left or right range and not both

                
                 else lo = mid+1; //else change the range normally only
                }
            else
                hi = mid; //shifting to the left range
        }
        //cout<<nums[ans];
        return nums[lo];
    }
};