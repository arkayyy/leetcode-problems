class Solution {
public:
    //INTUITION: Min. path could only be obtained if we keep on adding the minimum possible value for every element from the previous row
    //If we keep on doing this, at last we would be left with just one row containing all falling path sums. We return the min.
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 1; i<n; i++)
            for(int j = 0; j<m; j++)
                matrix[i][j] += min({matrix[max(0,i-1)][max(0,j-1)], matrix[max(0,i-1)][j], matrix[max(0,i-1)][min(j+1,m-1)]});
        return *min_element(matrix[n-1].begin(), matrix[n-1].end());
    }
};