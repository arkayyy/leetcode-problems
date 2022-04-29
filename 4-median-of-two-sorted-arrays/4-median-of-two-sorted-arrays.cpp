class Solution {
public:
    //COMPLETE EXPLANATION: 
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if(len1<len2) return findMedianSortedArrays(nums2,nums1); //always taking nums2 as shorter array since we perform binary searching opn on it
        int i = 0, j = len2*2;
        while(i<=j)
        {
            int cut2 = i+((j-i)>>1);
            int cut1 = len1 + len2 - cut2; //see explanation
            
            double leftMax1 = cut1==0?INT_MIN:nums1[(cut1-1)>>1];
            double leftMax2 = cut2==0?INT_MIN:nums2[(cut2-1)>>1];
            double rightMin1 = cut1==(len1*2)?INT_MAX:nums1[(cut1)>>1];
            double rightMin2 = cut2==(len2*2)?INT_MAX:nums2[(cut2)>>1];
            
            if(leftMax1 > rightMin2) i = cut2+1; //nums1's left half is too big, it needs to be contracted. i.e. cut1 in nums1 shifted to left and cut2 in nums2 shifted to right
            else if(leftMax2 > rightMin1) j = cut2-1; //nums2's left half is too big, it needs to be contracted. i.e. cut2 in nums2 shifted to left and cut1 in nums1 shifted to right
            
            else return ((max(leftMax1,leftMax2)+min(rightMin1,rightMin2))/2); //perfect cuts found for finding median...see explanation for formula
        }
        return -1;
    }
};