class NumMatrix {
public:
    int n,m;
    vector<vector<int>> prefix;
    //int prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        prefix = vector<vector<int>>(n+1,vector<int>(m+1,0));
        for(int i = 1; i<=n;++i)
            for(int j = 1; j<=m; ++j)
                prefix[i][j] = prefix[i][j-1]+prefix[i-1][j]-prefix[i-1][j-1] + matrix[i-1][j-1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // int sum = 0;
        // for(int i = row1; i<=row2; ++i)
        //     sum += prefix[i][col2] - (col1>=1?prefix[i][col1-1]:0);
        // return sum;
        
        return prefix[row2+1][col2+1] - prefix[row2+1][col1] - prefix[row1][col2+1] + prefix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */