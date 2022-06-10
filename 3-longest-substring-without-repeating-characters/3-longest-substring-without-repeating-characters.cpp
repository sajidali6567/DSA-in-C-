class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int s = 0, e = 0;
        unordered_map<char, int>mp;
        
        int ans = 0, n = str.size();
        
        while(e < n) {
            char c = str[e];
            
            if(mp.find(c) != mp.end() && mp[c] >= s) {
                s = mp[c]+1;
                mp[c] = e;
            }
            
            ans = max(ans, e-s+1);
            mp[c] = e++;

        }
        return ans;
    }
};