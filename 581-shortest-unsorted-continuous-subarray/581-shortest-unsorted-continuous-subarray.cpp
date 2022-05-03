class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //Brute force O(N logN) -  we can sort the array and find the first dissimilar element and the last dissimilar element between the sorted and unsorted array and O/P their difference in index 
        
        
        //======================APPROACH 2 - Using a MONOTONIC STACK: - O(N) SC:O(N) ====================//
        //A monotonic queue/deque can also be used...
        int n = nums.size();
        stack<pair<int,int>> st;
        bool first = true;
        
        int firstViolation = nums.size(), lastViolation = -1;
        
        
        //finding the first violation from the beginning
        for(int i=0; i<nums.size(); i++)
        {
            if(!st.empty() && nums[i]<st.top().first)
            {
                int prev = -1;
                while(!st.empty() && nums[i]<st.top().first)
                {
                    firstViolation = min(firstViolation, st.top().second); 
                    st.pop();
                }
                
            }
            st.push({nums[i],i});
        }
        while(!st.empty()) st.pop();//reinitialising empty stack
        
        //finding the first violation from the end(or the last violation)
        for(int i =nums.size()-1; i>=0; i--)
        {
            if(!st.empty() && nums[i]>st.top().first)
            {
                while(!st.empty() && nums[i]>st.top().first)
                {
                    lastViolation = max(lastViolation,st.top().second); 
                    st.pop();
                }
            }
            st.push({nums[i],i});
         }
        
        int ans =  (lastViolation - firstViolation +1);
        
        return ans>=0?ans:0;
    }
};