class Solution {
public:
    int uniquePaths(int m, int n) {
        // Tabulation
        
        // we will start with m-1 and go till 0,0
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m-1, n-1, dp);
    }
    
    int helper(int i, int j, vector<vector<int>>& dp) {
        // Base Case
        if(i == 0 && j==0) return 1; // Reached Destination
        if(i<0 || j<0) return 0; // Out of the boundary
        if(dp[i][j] != -1) return dp[i][j]; 
        // Do All the stuffs
        int up = helper(i-1, j, dp);
        int left = helper(i, j-1, dp);
        // return sum
        return dp[i][j] = up+left;
    }
};