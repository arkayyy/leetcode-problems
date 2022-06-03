class NumMatrix {
public:
    int n,m;
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        prefix = vector<vector<int>>(n,vector<int>(m,0));
        for(int i = 0; i<n;++i)
            for(int j = 0; j<m; ++j)
                prefix[i][j] = j==0?matrix[i][j]:(prefix[i][j-1]+matrix[i][j]);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i<=row2; ++i)
            sum += prefix[i][col2] - (col1>=1?prefix[i][col1-1]:0);
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */