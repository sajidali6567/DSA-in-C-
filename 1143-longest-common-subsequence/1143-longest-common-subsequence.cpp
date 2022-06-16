class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int M = text1.length(), N = text2.length();
        vector<vector<int>> dp(M+1, vector<int>(N+1,0));

        for(int m=1;m<M+1;m++) {
            for(int n=1;n<N+1;++n) {
                if(text1[m-1] == text2[n-1] ) {
                    dp[m][n] = 1 + dp[m-1][n-1];
                } else {
                    dp[m][n] = max(dp[m][n-1], dp[m-1][n]);
                }
            }
        }
            
        return dp[M][N];    
    }
};