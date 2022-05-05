class Solution {
public:
    // Space Optimization
    int uniquePaths(int m, int n) {
        // take array to maintain one row
        vector<int> prev(n, 0);
        // Tabulation
        for(int i=0;i<m;i++) {
            vector<int> temp(n, 0); // to calculate current row
            for(int j=0;j<n;++j) {
                if(i == 0 || j == 0) {
                     temp[j] = 1;
                } else {
                        temp[j] = prev[j] +  temp[j-1];            
                }
            }
            prev = temp;
        }
        return prev[n-1];
    }
    /*
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // Tabulation
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;++j) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];            
                }
            }
        }
        return dp[m-1][n-1];
    }*/
};