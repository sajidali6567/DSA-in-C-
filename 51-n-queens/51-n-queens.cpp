class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<vector<bool>> grid(n, vector<bool>(n, false));
        int count = 0;
        vector<string> temp;
        solve(0, res, grid, n, count, temp);
        cout << "count = " <<  count << endl;
        return res;
    }
    void solve(int col, vector<vector<string>>& res, vector<vector<bool>>& grid, int n, int& count, vector<string> temp) {
        if(col == n) { count++; res.push_back(temp); return;}
        string str(n, '.');
        for(int row=0;row<n;row++) {
            if(isSafeToPlaceQueen(grid, row, col, n)) {
                    grid[row][col] = true;
                    str[row] = 'Q'; temp.push_back(str);
                    solve(col+1, res, grid, n, count, temp);
                    grid[row][col] = false;
                    str[row] = '.';temp.pop_back();
            }
        }
    }
    bool isSafeToPlaceQueen(vector<vector<bool>>& grid, int row, int col, int n) {
        if(col == 0) return true;
        // check row
        for(int j=0;j<col;j++) {
            if(grid[row][j]) return false;
        }
        // check upper diagonal
        int i = row - 1, j = col-1;
        while(i>=0 && j >=0) {
            if(grid[i][j]) return false;
            i--;j--;
        }
        // check lower diagonal
        i = row + 1, j = col -1;
        while(i < n && j >=0) {
            if(grid[i][j]) return false;
            i++;j--;
        }
        return true;
    }
};