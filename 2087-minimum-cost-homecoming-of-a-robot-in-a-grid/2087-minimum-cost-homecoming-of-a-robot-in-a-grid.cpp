class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans = 0;
        for(int i = homePos[0]; i != startPos[0]; i += i > startPos[0] ? -1 : 1)  // move row-wise from end to start
            ans += rowCosts[i];
        for(int i = homePos[1]; i != startPos[1]; i += i > startPos[1] ? -1 : 1)  // move column-wise from end to start
            ans += colCosts[i];
        return ans;
    }
};