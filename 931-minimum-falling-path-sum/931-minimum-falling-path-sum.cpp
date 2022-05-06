class Solution {
public:      
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = 1e9;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int j=0;j<n;++j) {
            dp[0][j] = matrix[0][j];
        }
        for(int i=1;i<n;++i) {
            for(int j=0;j<n;j++) {
                int leftD = 1e9, rightD = 1e9, up = 1e9;
                if(i>0 && j >0) leftD = matrix[i][j] + dp[i-1][j-1];
                if(i>0 && j+1<n) rightD = matrix[i][j] + dp[i-1][j+1];
                if(i>0) up = matrix[i][j] + dp[i-1][j];
                dp[i][j] = min(up, min(leftD, rightD));
            }
        }
        
        for(int j=0;j<n;++j) {
            mini = min(mini, dp[n-1][j]);
        }
        return mini;
    }
};