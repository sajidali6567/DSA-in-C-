class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> grid(n, string(n, '.'));
        solve(0, grid, n, res);
        return res;
    }
    void solve(int col, vector<string>& grid, int n, vector<vector<string>>& res) {
        if(col == n) { res.push_back(grid); return; }
        for(int row=0;row<n;row++) {
            if(isSafeToPlaceQueen(grid, row, col, n)) {
                    grid[row][col] = 'Q';
                    solve(col+1, grid, n, res);
                    grid[row][col] = '.';
            }
        }
    }
    bool isSafeToPlaceQueen(vector<string>& grid, int row, int col, int n) {
        // check row
        for(int j=0;j<col;j++) {
            if(grid[row][j] == 'Q') return false;
        }
        // check upper diagonal
        int i = row - 1, j = col-1;
        while(i>=0 && j >=0) {
            if(grid[i][j] == 'Q') return false;
            i--;j--;
        }
        // check lower diagonal
        i = row + 1, j = col -1;
        while(i < n && j >=0) {
            if(grid[i][j] == 'Q') return false;
            i++;j--;
        }
        return true;
    }
};