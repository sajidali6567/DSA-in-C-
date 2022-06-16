class Solution {
public:
    string longestPalindrome(string word1) {
        string word2(word1);
        reverse(word2.begin(), word2.end());
        int ans = 0, index = -1;
        // find longest common substring of word1 and word2
        int M = word1.size(), N = word2.size();
        vector<vector<int>> dp(M+1, vector<int>(N+1, 0));
        for(int i=1;i<=M;i++) {
            for(int j=1;j<=N;j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(dp[i][j] > ans ) {
                        string temp1 = word1.substr(i-dp[i][j], dp[i][j]);
                        string temp2 = word2.substr(N-i, dp[i][j]);
                        if(temp1 == temp2) {
                            ans = max(ans, dp[i][j]);
                            index = i;                            
                        }
                    }                   
                }
            }
        }
        string res = "";
        if(index != -1) res = word1.substr(index-ans, ans);            
        return res;
    }
};