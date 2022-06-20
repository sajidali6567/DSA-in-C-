class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 1e9));
        for(int i=m-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                if(i == m-1 && j == n-1) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int down = grid[i][j] + dp[i+1][j];
                int right = grid[i][j] + dp[i][j+1];
                dp[i][j] = min(down, right);
            }
        }
        return dp[0][0];
    }
};