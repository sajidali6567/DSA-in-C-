class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, ans = 0;
        unordered_set<char> mp;
        for(int end=0;end<s.size();end++) {
            while(mp.find(s[end]) != mp.end()) {
                mp.erase(s[start++]);
            }
            mp.insert(s[end]);
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};