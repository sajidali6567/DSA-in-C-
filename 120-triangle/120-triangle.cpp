class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0) return 0;
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int j=0;j<n;j++) {
            dp[m-1][j] = triangle[m-1][j];
        }
        
        for(int i=m-2;i>=0;i--) {
            for(int j=0;j<i+1;j++) {
                int down = triangle[i][j] + dp[i+1][j];
                int right = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, right);
            }
        }
        return dp[0][0];
    }
};