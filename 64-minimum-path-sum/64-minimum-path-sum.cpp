class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);
            
        for(int i=0;i<m;i++) {
            vector<int> cur(n, 0);
            for(int j=0;j<n;j++) {
                if(i == 0 && j==0) cur[j] =  grid[i][j];
                else {
                    int up = 1e9, left = 1e9;
                    if(i>0) up = grid[i][j] + prev[j];
                    if(j>0) left = grid[i][j] + cur[j-1];
                    cur[j] = min(up, left);
                }
            }
            prev = cur;
        }
            
        return prev[n-1];
    }
};