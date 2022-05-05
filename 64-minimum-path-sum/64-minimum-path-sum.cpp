class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m-1, n-1, grid, dp);
    }
    int helper(int i, int j, vector<vector<int>>& cost, vector<vector<int>>& dp) {
       // Base Case
        if(i == 0 && j==0) return cost[i][j];
        if(i <0 || j <0) return 1e9;
        // memo check
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int up = cost[i][j] + helper(i-1, j, cost, dp);
        int left = cost[i][j] + helper(i, j-1, cost, dp);
        return dp[i][j] = min(up, left);
    }
};