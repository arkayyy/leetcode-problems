class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        //=========================O(N) APPROACH - Monotonic Stack/Queue ===========================//
        stack<int>st;
        
        unordered_map<int,int> mp;
        
        for(int i = 0; i<nums2.size(); i++)
        {
            
            while(!st.empty() && nums2[i]>st.top()) //for aall elements in st smaller than nums2[i], nums2[i] will be the next greater elements for all such elements
            {
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        
        for(int i = 0; i<nums1.size(); i++)
        {
            if(mp.find(nums1[i])!=mp.end())
                nums1[i] = mp[nums1[i]];
            else
                nums1[i] = -1;
        }
        return nums1;
    }
};