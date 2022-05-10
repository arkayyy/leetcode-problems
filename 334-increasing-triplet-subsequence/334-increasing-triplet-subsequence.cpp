class Solution {
public:
    //INTUITION: We check if the min. element on the left of any index is less than the current element, and the max element on the right is more than current element
    //only in that case, it will satisfy the condition for increasing triplet subsequence...!
    bool increasingTriplet(vector<int>& nums) {
//         if(nums.size()<3)return false;
//         vector<int> maxRight(nums.size()); //to access maximum element on right of any index
//         vector<int> minLeft(nums.size()); //to access min element on left of any index
//         minLeft[0] = nums[0]; maxRight[nums.size()-1] = nums.back();
//         for(int i = 1; i<nums.size();i++) {minLeft[i] = min(nums[i], minLeft[i-1]); maxRight[nums.size()-1-i] = max(nums[nums.size()-i-1],maxRight[nums.size()-i]); }
        
//         for(int i = 1; i<nums.size()-1; i++)
//         {
//             if(minLeft[i-1]<nums[i] && nums[i]<maxRight[i+1])
//                 return true;
//         }
//         return false;
        
        //Space optimized solution:-
        int a = INT_MAX, b = INT_MAX;
        for(auto n: nums)
        {
            if(n<a) a = n;
            if(n>a && n<b) b = n;
            if(b<n) return true; //means a<b<n
        }
        return false;
    }
};