class Solution {
public:
    bool dp[101][101];
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() > s1.size() + s2.size()) return false;
        memset(dp, false, sizeof(dp));
        for(int i=s1.size();i>=0;i--) {
            for(int j=s2.size();j>=0;j--) {
                    if(i== s1.size() && j == s2.size() && i+j == s3.size()) {
                        dp[i][j] = true;
                        continue;
                    }
                    bool b = false;
                    if(i+j < s3.size() && s3[i+j] == s1[i]) {
                        b = dp[i+1][j];
                    }
                    if(i+j < s3.size() && s3[i+j] == s2[j]) {
                        b = b || dp[i][j+1];
                    }
                    dp[i][j] = b;
            }
        }
        return dp[0][0];
    }
};