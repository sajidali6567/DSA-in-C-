class Solution {
public:
    int f(string& s, int n, vector<int>& dp) {
        if(n == 0 || n ==1) {
            return 1;
        }
        if(s[0] == '0') return 0;
        
        if(dp[n] != -1) return dp[n];
        int count = 0;
        if(s[n-1] > '0') {
            count = f(s, n-1, dp);
        }
        if(s[n-2] == '1' || (s[n-2] == '2' && s[n-1] < '7') ) {
            count += f(s, n-2, dp);
        }
        return dp[n] = count;
    }
    int numDecodings(string s) {
        vector<int> dp(s.length()+1, -1);
        if (s.length() == 0 || (s.length() == 1 && s[0] == '0'))
            return 0;
        return f(s, s.length(), dp);
    }
};