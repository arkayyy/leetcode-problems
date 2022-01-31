class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        
        for(int i = 0; i<=heights.size(); i++)
        {
            while(!st.empty() && (i==heights.size() || heights[i]<=heights[st.top()])) // will loop until the elements in stack are in increasing order from top to bottom while including heights[i]
            {
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i-st.top()-1;
                
                maxArea = max(maxArea, height*width);
            }
            st.push(i);
        }
        
        return maxArea;
    }
};