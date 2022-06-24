class Solution {
public:
    vector<vector<string>> ans;
    void solve(string s, unordered_set<string>& dict, int index, vector<int>& dp, vector<string>& cur) {
        if(index >= s.size()) {
            ans.push_back(cur);
            return;
        }
        
        string temp = "";
        for(int i=index;i<s.size();i++) {
            temp += s[i];
            if(dict.find(temp) != dict.end()) {
                cur.push_back(temp);
                solve(s, dict, i+1, dp, cur);
                cur.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> res;
        vector<string> cur;
        solve(s, dict, 0, dp, cur);
        for(auto x:ans) {
            string temp;
            for(auto y:x) {
                temp += y + " ";
            }
            temp.pop_back();
            res.push_back(temp);
        }
        return res;
    }
};