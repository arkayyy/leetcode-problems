class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<pair<int,int>> st; //{element, index}
        int firstViolation = nums.size(), lastViolation = -1; 
        //to maintain an increasing order from left to right, we need to take an increasing monotonic stack (increasing from bottom to top) from left to right
        for(int i = 0; i<nums.size(); i++)
        {
            while(!st.empty() && nums[i]<st.top().first)
                {firstViolation = min(firstViolation, st.top().second); st.pop();  }
            st.push({nums[i], i});
        }
        
        while(!st.empty()) st.pop();
        //to maintain an increasing order from left to right, we need to take an decreasing monotonic stack (decreasing from bottom to top) while traversing from right to left
        for(int i = nums.size()-1; i>=0; i--)
        {
            while(!st.empty() && nums[i]>st.top().first)
            { lastViolation = max(lastViolation, st.top().second); st.pop(); }
            st.push({nums[i],i});
        }
        int res = lastViolation-firstViolation +1;
        return res<0?0:res;
    }
};