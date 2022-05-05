class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0) return 0;
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(0, 0, triangle, m, dp);
    }
    int helper(int i, int j, vector<vector<int>>& triangle, int m, vector<vector<int>>& dp) {
        if(i>m-1 || j>i) return 1e9;
        if(j<m && i==m-1) {
            return triangle[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int down = triangle[i][j] + helper(i+1, j,triangle, m, dp);
        int right = triangle[i][j] + helper(i+1, j+1,triangle, m, dp);
        return dp[i][j] = min(down, right);
    }
};