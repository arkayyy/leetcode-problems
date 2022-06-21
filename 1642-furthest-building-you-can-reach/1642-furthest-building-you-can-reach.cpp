class Solution {
public:
    vector<vector<vector<int>>>dp;
    int util(int i, vector<int>&heights, int bricks,int ladders)
    {
        if(i==heights.size()-1 ) return 0;
        
        if(dp[i][bricks][ladders]!=-1) return dp[i][bricks][ladders];
        int res = 0;
        if(heights[i+1]>heights[i] && ladders>=1) res = 1+util(i+1,heights,bricks,ladders-1);
        if(heights[i+1]>heights[i] && bricks>=heights[i+1]-heights[i]) res = max(res,1+util(i+1,heights,bricks-(heights[i+1]-heights[i]),ladders));
        if(heights[i+1]<=heights[i]) res = max(res,1+util(i+1,heights,bricks,ladders));
        
        return dp[i][bricks][ladders]= res;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        //Memory limit exceeded due to constraints:-
        // dp = vector<vector<vector<int>>> (heights.size(),vector<vector<int>>(bricks+1,vector<int>(ladders+1,-1)));
        // return util(0,heights,bricks,ladders);
        
        //PQ solution:- O(N)Time O(N)Space
        priority_queue<int> pq;
        for(int i = 0; i<heights.size()-1; ++i)
        {
            if(heights[i+1]>heights[i]) pq.push(heights[i]-heights[i+1]);
            if(pq.size()>ladders)
            {
                bricks+=pq.top();
                pq.pop();
            }
            if(bricks<0) return i;
        }
        return heights.size()-1;
    }
};