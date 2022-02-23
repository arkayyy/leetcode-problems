class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //==============APPROACH - O(N) - Monotonic Stack/Queue ================================//
        stack<pair<int,int>> st;
        vector<int> ans(nums.size(),-1);
        for(int i = 0; i<2*nums.size(); i++)
        {
            while(!st.empty() && nums[i%nums.size()]>st.top().first) //GENERAL RULE: for all the elements in the stack that are less than the current index element in the array, the next greater element of all those elements will be nums[i]
            {
                ans[st.top().second % nums.size()] = nums[i%nums.size()];
                st.pop();
            }
            st.push({nums[i%nums.size()],i});
        }
        return ans;
    }
};