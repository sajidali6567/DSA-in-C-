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
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, s3, 0, 0, 0);
    }
};