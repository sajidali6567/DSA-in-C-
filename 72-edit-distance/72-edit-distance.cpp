class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& word1, string& word2, int i, int j) {
        // Base Case
        if(i == word1.size()) {
            return word2.size()-j;
        }
        if(j == word2.size()) {
            return word1.size()-i;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) {
            return dp[i][j] = solve(word1, word2, i+1, j+1);
        }
        // try all the possibility at current position in word
        int replace = 1 + solve(word1, word2, i+1, j+1);
        int insert = 1 + solve(word1, word2, i, j+1);
        int del = 1 + solve(word1, word2, i+1, j);
        return dp[i][j] = min({replace, insert, del});
    }
    int minDistance(string word1, string word2) {
        dp.resize(word1.size(), vector<int>(word2.size(), -1));
        return solve(word1, word2, 0, 0);
    }
};