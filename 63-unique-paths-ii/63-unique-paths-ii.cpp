class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacle) {
        if(obstacle.size() == 0) return 0;
        int m = obstacle.size();
        int n = obstacle[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;++j) {
                if(obstacle[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    if(i == 0 && j == 0) {
                        dp[i][j] = 1;
                    } else {
                        if(i-1>=0) {
                            dp[i][j] += dp[i-1][j];
                        }
                        if(j-1>=0) {
                            dp[i][j] += dp[i][j-1];
                        }
                    }
                }
            }
        }
        return dp[m-1][n-1];     
    }
};