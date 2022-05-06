class Solution {
public:
    //INTUITION: We take one variable for iterating in nums1 and another for iterating in nums2 (traverse from right to left in both)
    //A third variable is taken to traverse from last of nums1 where 0's are placed as extra space.
    //The idea is to place the bigger element out of the two indexes(nums1 and nums2) at every step in the place of third index variable...
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;
        while(j>=0)
        {
            if(i>=0 && nums1[i]>nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
    }
};