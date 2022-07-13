class Solution {
public:
    string s; string p;
    vector<vector<int>> dp;
    bool solve(int i, int j) {
        // pattern exhausted and string is covered or not
        if(j == p.size()) {
            return i == s.size();
        }
        if(i == s.size()) {
            // check if pattern is exhausted or rest of the patterns are with * value
            while(j<p.size()) {
                if(p[j] != '*') {
                    return false;
                }
                j++;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(i+1, j+1);
        }
        if(p[j] == '*') {
            if(solve(i+1, j) || solve(i, j+1)) return dp[i][j] = true;
        }
        return dp[i][j] = false;
    }
    bool isMatch(string str, string pattern) {
        dp.resize(str.size(), vector<int>(pattern.size(), -1));
        s = str; p = pattern;
        return solve(0, 0);
    }
};