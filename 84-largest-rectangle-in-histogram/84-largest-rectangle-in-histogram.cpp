class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        //----------------------------------APPROACH 2-----------------------------------//
        
        //MOST OPTIMAL TC:O(N)+O(N) SC:O(N) Single Pass Approach:-
        stack<int> st;
        int maxArea = 0;
        
        for(int i = 0; i<=heights.size(); i++)
        {
            //INTUITITON: for the current height we assess all the bigger heights on the left and find area formed by current height with all such bigger heights on its left
            while(!st.empty() && (i==heights.size() || heights[i]<=heights[st.top()])) 
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