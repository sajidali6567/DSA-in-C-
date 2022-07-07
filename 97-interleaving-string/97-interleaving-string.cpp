class Solution {
public:
    int dp[101][101][201];
    bool solve(string& s1, string& s2, string& s3, int i, int j, int k) {
        if(i== s1.size() && j == s2.size() && k == s3.size()) {
            return true;
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int b = false;
        if(i < s1.size() && s3[k] == s1[i]) {
            b = solve(s1, s2, s3, i+1, j, k+1);
        }
        if(j < s2.size() && s3[k] == s2[j]) {
            b = b || solve(s1, s2, s3, i, j+1, k+1);
        }
        return dp[i][j][k] = b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() > s1.size() + s2.size()) return false;
        memset(dp, 0, sizeof(dp));
        for(int i=s1.size();i>=0;i--) {
            for(int j=s2.size();j>=0;j--) {
                for(int k = s3.size();k>=0;k--) {
                    if(i== s1.size() && j == s2.size() && k == s3.size()) {
                        dp[i][j][k] = true;
                        continue;
                    }
                    int b = false;
                    if(i < s1.size() && s3[k] == s1[i]) {
                        b = dp[i+1][j][k+1];
                    }
                    if(j < s2.size() && s3[k] == s2[j]) {
                        b = b || dp[i][j+1][k+1];
                    }
                    dp[i][j][k] = b;
                }
            }
        }
        return dp[0][0][0];
    }
};