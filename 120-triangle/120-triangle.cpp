class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=n-1;i>=0;i--) {
            for(int j=i;j>=0;j--) {
                int down = triangle[i][j] + dp[i+1][j];
                int right = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, right);
            }
        }
        return dp[0][0];
    }
};