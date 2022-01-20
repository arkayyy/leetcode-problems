class Solution {//EXPLANATION: https://leetcode.com/problems/132-pattern/discuss/94071/Single-pass-C%2B%2B-O(n)-space-and-time-solution-(8-lines)-with-detailed-explanation.
public:
    //INTUITION & ALGO: We move from end of the array and if we find any increasing pair... 
    //...we compute and store the number that has appaered on the right of the current number (which plays role of 3 in 1-3-2), that is just smaller than itself (which plays role of 2 in 1-3-2)
    //then we can search on the left of the current number for any number that is lesser than the stored no. above(which plays role of 1 in 1-3-2)..
    //that makes the 1-3-2 pattern perfectly.
    bool find132pattern(vector<int>& nums) {
        stack <int> st; //for storing all elements less than a number that appears on the right side of it...
        
        int store= INT_MIN;
        
        for(int i = nums.size()-1;  i>=0; i--)
        {
            if(nums[i]<store) return true; //we found the number that's less than 2 in 1-3-2, that serves the role of 1 in 1-3-2
            else
            {
                while(!st.empty() && nums[i]>st.top()) //we keep popping stack until there is no element less than nums[i] left in it
                {store = st.top(); st.pop();}//ultimately store variable stores a number on the right of nums[i] that's greater than it (plays role of 2 in 1-3-2)
            }
            st.push(nums[i]);
        }
        return false;
    }
};