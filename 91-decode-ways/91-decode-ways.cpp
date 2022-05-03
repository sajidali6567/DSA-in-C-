class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length()+1, -1);
        return decodeWays(s, s.length(), dp);
    }
    int decodeWays(string s, int k,vector<int>& dp) {
        if(k == 0 ) return 1;
        int st = s.length()-k;
        if(s[st] == '0') return 0;
        if(dp[k] != -1) {
            return dp[k];
        }
        // recursive call
        int result = decodeWays(s, k-1, dp);
        if(k>=2 && s.substr(st, 2) >= "10" && s.substr(st, 2) <= "26") {
            result += decodeWays(s, k-2, dp);
        }
        return dp[k] = result;
    }
};