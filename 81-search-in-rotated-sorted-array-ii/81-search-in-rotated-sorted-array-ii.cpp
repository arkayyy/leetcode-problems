class Solution {
public:
    //INTUITION: We detect the location of the pivot, and check if target lies in the part that doesn't contain the pivot first. 
    //If not, we continue our search in the part containing the pivot...
    bool search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            
            if(nums[mid]==target) return true;
            
            if(nums[lo]==nums[mid] && nums[mid]==nums[hi]) lo++,hi--; //IMPP: additional step since repeating elements are present
            
            else if(nums[mid]>nums[hi]) //the part between mid and hi has a pivot
            {
                if(target<nums[mid] && target>=nums[lo]) hi=mid-1; //since the part between lo and mid is still sorted, we check if target lies in this part
                else lo = mid+1; //otherwise continuing search in the part containing pivot
            }
            else if(nums[mid]<nums[lo]) //the part between lo and mid has a pivot
            {
                if(target>nums[mid] && target<=nums[hi]) lo = mid+1; //since the part between mid and hi is still sorted, we check if target lies in this part
                else hi = mid-1; //otherwise continuing search in the part containing pivot
            }
            else //if no pivot exists in the current range between lo and hi, it will continue like normal binary search
            {
                if(target>nums[mid]) lo = mid+1;
                else hi = mid-1;
            }
        }
        return false;
    }
};