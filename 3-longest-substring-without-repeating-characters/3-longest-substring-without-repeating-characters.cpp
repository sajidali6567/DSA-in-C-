class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        // Windows starting and ending point
        int s = 0, e = 0, ans = 0;
        map<char, int> mp;
        while(e < str.size()) {
            char c = str[e];
            if(mp.find(c) != mp.end() && mp[c] >= s) {
                s = mp[c] + 1;
            }
            ans = max(ans, e-s+1);
            mp[c] = e++;
        }
        return ans;
    }
};