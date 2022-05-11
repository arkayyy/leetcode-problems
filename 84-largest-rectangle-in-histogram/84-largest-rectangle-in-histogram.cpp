class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        //----------------------------------APPROACH 2-----------------------------------//
        //ALGO: Monotonic stack (maintaining increasing order from bottom to top)
        
        //MOST OPTIMAL TC:O(N)+O(N) SC:O(N) Single Pass Approach:-
        stack<int> st;
        int maxArea = 0;
        
        for(int i = 0; i<=heights.size(); i++)
        {
            while(!st.empty() && ( i==heights.size() || heights[st.top()]>=heights[i] )) 
            {
                int height = heights[st.top()]; //for this height at index = st.top(), heights[i] at ith index(i.e current element) will act as the right smaller(right boundary), and the next st.top() will act as the left boundary for the area
                st.pop();
                int width;
                if(st.empty()) width = i - 0; //from starting of array, if stack is empty left boundary would be starting of the array
                else width = i-st.top()-1; //the width between the left boundary and right boundary
                
                maxArea = max(maxArea, height*width); //updating area
            }
            st.push(i);
        }
        
        return maxArea;
    }
};