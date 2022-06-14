class Solution {
public:
    // returns the length of longest common substring
    int LCS(string X, string Y){
        vector<vector<int>> dp(X.size()+1, vector<int>(Y.size()+1, 0));
        int ans = 0;
        for(int i=1;i<=X.size();i++) {
            for(int j=1;j<=Y.size();j++) {
                if(X[i-1] == Y[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
    
    int minDistance(string word1, string word2) {
        int lcsLength = LCS(word1, word2);
        return word1.size()-lcsLength + word2.size()-lcsLength;
    }
};