class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int row = m-1, col = 0;
        while(row >= 0 && row < m && col >=0 &&  col < n) {
            int top = row>0?mat[row-1][col]:-1;
            int down = row<m-1?mat[row+1][col]:-1;
            int right = col<n-1?mat[row][col+1]:-1;
            int left = col>0?mat[row][col-1]:-1;
            if(mat[row][col] > top && mat[row][col] > down && mat[row][col] > left && mat[row][col] >right ) {
                return {row, col};
            } else if (top > mat[row][col]) {
                row--;
            } else if (down > mat[row][col]) {
                row++;
            } else if (left > mat[row][col]) {
                col--;
            } else {
                col++;
            }
        }
        return {};
    }
};