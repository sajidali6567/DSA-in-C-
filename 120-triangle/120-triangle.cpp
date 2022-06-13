class Solution {
public:
    int solve(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp) {
        if(i == triangle.size()) return 0; 
        if(dp[i][j] != -1) return dp[i][j];
        int down = triangle[i][j] + solve(triangle, i+1, j, dp);
        int right = triangle[i][j] + solve(triangle, i+1, j+1, dp);
        return dp[i][j] = min(down, right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(triangle, 0, 0, dp);
    }
};