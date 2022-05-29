class Solution {
public:
    //INTUITION: For every element, we check on its right that how many elements can be dissolved using it. Maximum number of such elements found is our answer.
    
    //ALGO: We use a monotonic stack to check for such a decreasing sequence from right to left, because an element can only dissolve elements on their right smaller than itself.
    //And we keep storing the no. of elements possible to be dissolved for every index in a dp array
    //For this algo, we have to traverse from the right end to starting of the array.
    int totalSteps(vector<int>& nums) {
        stack<int> st;
        int ans = 0;
        vector<int> dp(nums.size(),0);
        for(int i = nums.size()-1; i>=0; --i)
        {
            while(!st.empty() && nums[i]>nums[st.top()])//will run till we have a increasing sequence from right to left (or decreasing sequence from left to right starting from index i) 
            {
                ++dp[i]; //because there's one element to its right side for sure that it can dissolve/eliminate
                dp[i] = max(dp[i], dp[st.top()]); //now we also have to check whether there is another smaller number on the right side of nums[i] that can dissolve/eliminate even more no. of elements than nums[i] itself
                st.pop(); 
                ans = max(ans,dp[i]);
            }
            st.push(i);
        }
        return ans;
    }
};