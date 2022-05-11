class Solution {
public:
    int maxAreaHistogram(vector<int>& heights)
    {
        stack<int> st;
        int maxArea = 0;
        for(int i = 0; i<=heights.size(); i++)
        {
            while(!st.empty() && (i==heights.size() || heights[st.top()] >= heights[i]))
                  {
                      int height =  heights[st.top()];
                      st.pop();
                      int width;
                      if(st.empty()) width = i - 0;
                      else width = i-st.top()-1;
                      maxArea = max(maxArea, height*width);
                  }
            st.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<vector<int>> dp(2,vector<int>(matrix[0].size()));
        for(int j = 0; j<matrix[0].size(); j++) dp[0][j] = matrix[0][j]=='1'?1:0;
        
        int ans = maxAreaHistogram(dp[0]);
        for(int i = 1; i<matrix.size(); i++)
        {
            for(int j = 0; j<matrix[0].size(); j++)
            {
                if(matrix[i][j]=='0') {dp[1][j] = 0;}
                else dp[1][j]=1+dp[0][j];
            }
            dp[0] = dp[1];
            ans = max(ans,maxAreaHistogram(dp[0]));
        }
        return ans;
    }
};