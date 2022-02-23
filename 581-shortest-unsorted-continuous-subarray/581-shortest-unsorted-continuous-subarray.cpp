class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int,int>> st;
        stack<pair<int,int>> st1;
        bool first = true;
        
        int firstViolation = nums.size(), lastViolation = -1;
        
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
            
            if(!st1.empty() && nums[n-i-1]>st1.top().first)
            {
                while(!st1.empty() && nums[n-i-1]>st1.top().first)
                {
                    lastViolation = max(lastViolation,st1.top().second); 
                    st1.pop();
                }
            }
            st1.push({nums[n-i-1],n-i-1});
        
        }
        
        
//         for(int i =nums.size()-1; i>=0; i--)
//         {
            
//         }
        
        int ans =  (lastViolation - firstViolation +1);
        
        return ans>=0?ans:0;
    }
};