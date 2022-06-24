class Solution {
public:
    bool solve(string s, unordered_set<string>& dict, int index, vector<int>& dp) {
        if(index >= s.size()) return true;
        if(dp[index] != -1) return dp[index];
        string temp = "";
        for(int i=index;i<s.size();i++) {
            temp += s[i];
            if(dict.find(temp) != dict.end()) {
                if(solve(s, dict, i+1, dp)) {
                    return dp[index] = true;
                }
            }
        }
        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return solve(s, dict, 0, dp);
    }
};