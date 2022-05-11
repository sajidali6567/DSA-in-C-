class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(); int col = matrix[0].size();
        bool isSetByZeroThCol = false;
        // we are changing a[0][0] only if any 0th row element is zero
        // for 0th col we taking a variable which will determine if any entry in 0th col is zero or not
        for(int i=0;i<row;i++) {
            // if any of the element in 0th row is set to zero, mark the variable as 0
            if(matrix[i][0] == 0) isSetByZeroThCol = true;
            for(int j=1;j<col;++j) {
                if(matrix[i][j]==0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=row-1;i>=0;i--) {
            for(int j=col-1;j>0;--j) {
                if(matrix[i][0] ==0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if(isSetByZeroThCol) matrix[i][0] = 0;
        }
    }
};