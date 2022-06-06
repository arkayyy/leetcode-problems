class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        //=========================O(N) APPROACH - Monotonic Stack/Queue ===========================//
        stack<int>st;
        
        unordered_map<int,int> mp;

        //Finding and mapping next greater elements for all elements in nums2
        for(int i = nums2.size()-1; i>=0; --i)
        {
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            mp[nums2[i]] = st.empty()?-1:st.top();
            st.push(nums2[i]);
        }
        //Accessing and setting the next greater elements for all elements in nums1 (since nums1 is a subset of nums2, so all next greater elements have already been mapped)
        for(int i = 0; i<nums1.size(); ++i)
            nums1[i] = mp[nums1[i]];
        
        return nums1;
    }
};