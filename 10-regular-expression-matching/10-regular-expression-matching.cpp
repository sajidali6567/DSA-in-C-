class Solution {
public:
    string s, p;
    vector<vector<int>> dp;
    bool solve(int i, int j) {
        //  pattern is exhausted
        if(j == p.size()) {
            return i == s.size();
        }
        // string is exhaused
        if(i == s.size()) {
            if(p[j] == '*') {
                j += 1;
            }
            while(j+1 <p.size()) {
                if(p[j+1] != '*') {
                    return false;
                }
                j += 2;
            }
            return j == p.size();
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        bool match= false;
        if(s[i] == p[j] || p[j] == '.') {
            match = true;
            if(p[j+1] != '*') {
                return dp[i][j] = solve(i+1, j+1);
            }
        }
        
        if(p[j+1] == '*') {
            int ans = false;
            // skip the *
            ans = ans || solve(i, j+2);
            if(match) {
                ans = ans || solve(i+1, j);
            }
            return dp[i][j] = ans;
        }
        return dp[i][j] = false;
    }
    bool isMatch(string str, string pattern) {
        dp.resize(str.size(), vector<int>(pattern.size(), -1));
        s = str; p = pattern;
        return solve(0, 0);
    }
};