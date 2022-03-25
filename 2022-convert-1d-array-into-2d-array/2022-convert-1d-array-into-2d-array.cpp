class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n != original.size()) return {};
        int r = 0, c = 0;
        vector<vector<int>> ans(m, vector<int>(n));
        int i = 0;
        
        while(r<m)
        {
            ans[r][c] = original[i];
            if(c==n-1)
            {
                r++;
                c=0;
            }
            else
                c++;
            i++;
        }
        return ans;
    }
};