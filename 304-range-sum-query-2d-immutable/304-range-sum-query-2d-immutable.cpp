class NumMatrix {
public:
    vector<vector<int>> psm;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> temp(m+1, vector<int>(n+1, 0));
        psm = temp;
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                psm[i][j] = psm[i-1][j] + psm[i][j-1] + matrix[i-1][j-1] - psm[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // General formula to obtain the sum of a rectangle using two co-ord
        // psm[row2][col2] - psm[row1-1][col2]  - psm[row2][col1-1]  + psm[row1-1][col1-1]
        // Adding +1 in each index as we took psm as 1 based indexing
        return psm[row2+1][col2+1] - psm[row1][col2+1] - psm[row2+1][col1] + psm[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */